#include "src/NumberBig/NBop.h"

void WORD_MUL(WORD a,WORD b,WORD_T low,WORD_T high){
    WORD HALF_MASK = WORDMAX>>HALFWORDSIZE;
    WORD al, ah, bl, bh;
    WORD lowtmp, hightmp, midtmp;
    WORD midtmp1, midtmp2;
    ah = a >> HALFWORDSIZE;
    al = a & HALF_MASK;
    bh = b >> HALFWORDSIZE;
    bl = b & HALF_MASK;
    /* this can be optimized here using divide algorithm ?*/
    lowtmp = al * bl;
    midtmp1 = al * bh;
    midtmp2 = ah * bl;
    hightmp = ah * bh;
    midtmp = midtmp1 + midtmp2;
    /* end */
    uint64_t carry1 = midtmp < midtmp1;
    *low = lowtmp + ((midtmp & HALF_MASK) << HALFWORDSIZE);
    uint64_t carry2 = (*low) < lowtmp;
    *high = hightmp + (midtmp >> HALFWORDSIZE) + (carry1 << HALFWORDSIZE) + carry2;
}

void mulful(NB_T src1, NB_T src2, NB_T mtarget_low ,NB_T mtarget_high){
    uint64_t tmptarget[2*MAX_number_word] = {0};
    uint64_t high, low, carry;
    int pos;
    for (int i = 0; i < MAX_number_word; i++)
    {
        carry = 0;
        pos = 0;
        for (int j = 0; j < MAX_number_word; j++)
        {
            pos = i + j;
            WORD_MUL(src1->getval(i), src2->getval(j), &low, &high);
            low += carry;
            high += low < carry;
            tmptarget[pos] += low;
            carry = high + (tmptarget[pos] < low);
        }
        tmptarget[pos + 1] += carry;
    }
    /* copy tmptarget to mtarget_high&mtarget_low */
    mtarget_low->setary(tmptarget,MAX_number_word);
    mtarget_high->setary(&(tmptarget[MAX_number_word]),MAX_number_word);
    mtarget_high->setsig(src1->getsig() == src2->getsig() ? POS : NEG);
    mtarget_low->setsig(POS);
}

void mullow(NB_T src1, NB_T src2, NB_T mtarget){
    NB tmptarget = NB();
    NB_T target = &tmptarget;
    uint64_t high, low, carry;
    int pos;
    target->setzero();
    target->setsig(src1->getsig() == src2->getsig() ? POS : NEG);
    for (int i = 0; i < MAX_number_word; i++)
    {
        carry = 0;
        pos = 0;
        for (int j = 0; j < MAX_number_word; j++)
        {
            pos = i + j;
            if (pos >= MAX_number_word)
            {
                continue;
            }
            WORD_MUL(src1->getval(i), src2->getval(j), &low, &high);
            low += carry;
            high += low < carry;
            target->setval(target->getval(pos)+low,pos);
            carry = high + (target->getval(pos) < low);
        }
        if (pos + 1 < MAX_number_word)
        {
            target->setval(target->getval(pos+1)+carry,pos+1);
        }
    }
    copy(target, mtarget);

}

void square(NB_T src, NB_T target){
    mullow(src,src,target);
}

void squareful(NB_T src,NB_T low,NB_T high){
    mulful(src,src,low,high);
}