#include "src/NumberBig/NBop.h"


void copy(NB_T s, NB_T t)
{
    t->setsig(s->getsig());
    for (int i = 0; i < MAX_number_word; i++)
    {
        t->setval(s->getval(i),i);
    }
}

void cnd_add(NB_T src1, NB_T src2, NB_T target, sig_t neg)
{
    WORD carry = 0;
    WORD carry1 = 0;
    WORD carry2 = 0;
    WORD tmp;
    if ((src1->getsig() == POS && src2->getsig() == neg) || (src1->getsig() == NEG && src2->getsig() != neg))
    {
        /* add src1 with src2 , the target sig is same with src1 */
        target->setsig(src1->getsig());
        for (int i = 0; i < MAX_number_word; i++)
        {
            tmp = src1->getval(i) + src2->getval(i);
            carry1 = tmp < src1->getval(i);
            target->setval(tmp+carry,i);
            carry2 = target->getval(i) < tmp;
            carry = carry1 | carry2;
        }
    }
    else
    {
        /* sub src1 using src2 , the target sig need to be compared src1 with src2 */
        NB_T bigger, smaller;
        if (cmpabs(src1, src2) > 0)
        {
            target->setsig(src1->getsig());
            bigger = src1;
            smaller = src2;
        }
        else
        {
            target->setsig(SIG_OPPSITE(src1->getsig()));
            smaller = src1;
            bigger = src2;
        }
        for (int i = 0; i < MAX_number_word; i++)
        {
            tmp = bigger->getval(i) - smaller->getval(i);
            carry1 = tmp > bigger->getval(i);
            target->setval(tmp - carry,i);
            carry2 = target->getval(i) > tmp;
            carry = carry1 | carry2;
        }
    }
}

void add(NB_T src1, NB_T src2, NB_T target)
{
    NB mtarget = NB();
    cnd_add(src1, src2, &mtarget, POS);
    copy(&mtarget,target);
}

void sub(NB_T src1, NB_T src2, NB_T target)
{
    NB mtarget = NB();
    cnd_add(src1, src2, &mtarget, NEG);
    copy(&mtarget,target);
}

void inc(NB_T src, NB_T target)
{
    NB t = NB();
    NB_T tmp = &t;
    tmp->setone();
    add(src, tmp, target);
}

void dec(NB_T src, NB_T target)
{
    NB t = NB();
    NB_T tmp = &t;
    tmp->setone();
    sub(src, tmp, target);
}

int addmod(NB_T src1, NB_T src2, NB_T target, NB_T mod)
{
    if (!(src2->getsig() == POS && src1->getsig() == POS))
    {
        return 0;
    }
    if (cmp(target, mod) >= 0 || cmp(src2, mod) >= 0)
    {
        return 0;
    }
    add(src1, src2, target);
    if (cmp(target, mod) > 0)
    {
        sub(target, mod, target);
    }
    return 1;
}

int submod(NB_T src1, NB_T src2, NB_T target, NB_T mod)
{
    if (!(src2->getsig() == POS && src1->getsig() == POS))
    {
        return 0;
    }
    if (cmp(target, mod) >= 0 || cmp(src2, mod) >= 0)
    {
        return 0;
    }
    sub(src1, src2, target);
    if (target->getsig() == NEG)
    {
        add(target, mod, target);
    }
    return 1;
}