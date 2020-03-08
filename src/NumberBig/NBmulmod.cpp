#include "src/NumberBig/NBop.h"
/* using Montgomery algorithm to implement multiplication-then-modular */
/* paper: [2017eprint]Montgomery Arithmetic from a Software Perspective */

#define RSize MAX_number_bits

/* precomputation r^2, u = -N^{-1} \mod r */
int precomputation(NB_T mod, NB_T u, NB_T rsq)
{
    /* define MAX_NB */
    NB MAX_NB;
    MAX_NB.getmax();
    /* precomputation rsq = r^2 mod m*/
    NB c0 = NB(1);
    c0.lshift(RSize-1); 
    for(int i=0;i<RSize+1;i++){
        addmod(&c0,&c0,&c0,mod);
    }
    copy(&c0,rsq);
    /* precomputation u = -N^{-1} \mod r using exgcd algorithm*/
    /* u = -N^{-1} \mod r ,r = 2^k = P+N */
    /* wr-uN = 1,r = 2^k = P+N */
    /* wP + (w-u)N = 1 , P<2^k */
    NB w,wminusu,P,gcd;
    /* P = r-mod */
    sub(&MAX_NB,mod,&P);
    inc(&P,&P);
    exgcd(&P,mod,&w,&wminusu,&gcd);
    /* assert gcd */
    if(!gcd.isone()){
        return 0;
    }
    /* u = w + wminusu */
    add(&w,&wminusu,u);
    return 1;
}

/* Montgomery algorithm : M(A,B,N,R) = A*B*R^{-1}<N */
int Montgomery(NB_T A, NB_T B, NB_T N,NB_T u,NB_T result)
{
    NB plow = NB();
    NB phigh = NB();
    NB qlow = NB();
    NB qhigh = NB();
    NB nqlow = NB();
    NB nqhigh = NB();
    NB clow = NB();
    NB chigh = NB();
    mulful(A,B,&plow,&phigh);
    mulful(u,&plow,&qlow,&qhigh);
    mulful(&qlow,N,&nqlow,&nqhigh); 
    add(&nqhigh,&phigh,&chigh);
    if(!clow.iszero()){
        inc(&chigh,&chigh);
    }
    if(cmp(&chigh,N)>=0){
        sub(&chigh,N,result);
    }else{
        copy(&chigh,result);
    }
}

int mulmod(NB_T src1, NB_T src2, NB_T target, NB_T mod)
{
    NB u = NB();
    NB rsq = NB();
    NB one = NB(1);
    NB Apro = NB();
    NB Bpro = NB();
    NB Cpro = NB();
    /* computation r^2 & -u^{-1} */
    precomputation(mod,&u,&rsq);
    /* change src1 & src2 to Apro & Bpro in montgomery space */
    Montgomery(src1,&rsq,mod,&u,&Apro);
    Montgomery(src2,&rsq,mod,&u,&Bpro);
    /* Apro*Bpro->Cpro in montgomery space */
    Montgomery(&Apro,&Bpro,mod,&u,&Cpro);
    /* change Cpro to target */
    Montgomery(&Cpro,&one,mod,&u,target);
}

int mulmod_acc(NB_T src1,NB_T src2,NB_T target,NB_T mod,NB_T u,NB_T rsq){
    NB Apro = NB();
    NB Bpro = NB();
    NB Cpro = NB();
    NB one = NB(1);
    Montgomery(src1,rsq,mod,u,&Apro);
    Montgomery(src2,rsq,mod,u,&Bpro);
    Montgomery(&Apro,&Bpro,mod,u,&Cpro);
    Montgomery(&Cpro,&one,mod,u,target);
}