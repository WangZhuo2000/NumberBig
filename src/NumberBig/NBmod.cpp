#include "src/NumberBig/NBop.h"

/* paper: Division by Invariant Integers using Multiplication 1995*/
/* 有优化，没做，除法的优化似乎有不少，libgmp实现的真棒，然而我真的不想看那些论文 */
/* 就是textbook division */

int zeroword(WORD A){
    int count = 0;
    WORD B;
    while(1){
        B = A>>(WORDSIZE-1-count);
        B = B&1;
        if(B==0){
            count += 1;
        }else{
            break;
        }
    }
    return count;
}

int zeroheaders(NB_T x){
    int count = 0;
    WORD A;
    for(int i=MAX_number_word-1;i>=0;i--){
        A = x->getval(i);
        if(A==0){
            count += WORDSIZE;
        }else{
            break;
        }
    }
    return count+zeroword(A);
}

void divrem(NB_T a,NB_T b,NB_T q,NB_T r){
    int bheaders = zeroheaders(b);
    NB ret,bt,qt;
    copy(a,&ret);
    copy(b,&bt);
    bt.lshift(bheaders);
    qt.setzero();
    for(int i=0;i<bheaders;i++){
        qt.lshift(1);
        if(cmp(&ret,&bt)>=0){
            sub(&ret,&bt,&ret);
            inc(&qt,&qt);
        }
        bt.rshift(1);
    }
    qt.lshift(1);
    if(cmp(&ret,&bt)>=0){
        sub(&ret,&bt,&ret);
        inc(&qt,&qt);
    }
    copy(&ret,r);
    copy(&qt,q);
}

/* a \mod b = m */
void mod(NB_T a,NB_T b,NB_T m){
    NB c=NB();
    divrem(a,b,&c,m);
}
