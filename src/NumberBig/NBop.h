#pragma once

#include "src/NumberBig/NB.h"

/* implemented in NBcmp.cpp */
/* if a>b return 1 ;if a=b return 0; if a<b return -1*/
int cmp(NB_T a, NB_T b);
int cmpabs(NB_T a, NB_T b);
/* NBcmp.cpp end */


/* implemented in NBlinearop.cpp */
void copy(NB_T s, NB_T t);

void cnd_add(NB_T src1, NB_T src2, NB_T target, sig_t neg); /* implemented in nbadd.cpp */
/* src1+src2->target */
void add(NB_T src1, NB_T src2, NB_T target);
/* src1-src2->target */
void sub(NB_T src1, NB_T src2, NB_T target);

/* target = src+1 */
void inc(NB_T src, NB_T target);
/* target = src-1 */
void dec(NB_T src, NB_T target);
/* end */


/* Here addmod and submod is different with general mod . 
        * We need:
        * 1.src1 < mod && src2 < mod,which is useful in F_p.
        * 2.both src1 and src2 is positive.
        * return -1 means src1 or src2 doesn't fill the reduction. return 1 means success.
    */
int addmod(NB_T src1, NB_T src2, NB_T target, NB_T mod);
int submod(NB_T src1, NB_T src2, NB_T target, NB_T mod);

/* NBgcd.cpp */
/* need a,b is positive; */
void exgcd(NB_T a,NB_T b,NB_T s, NB_T t,NB_T gcd);
void gcd(NB_T a,NB_T b,NB_T gcd);
/* end */

/* NBmod.cpp */
void divrem(NB_T a,NB_T b,NB_T q,NB_T r);
void mod(NB_T a,NB_T b ,NB_T m);
WORD twobyone(WORD ah,WORD al,WORD b);
/* end */

/* NBmul.cpp begin */
/* target = src1*src2 */
void mulful(NB_T src1, NB_T src2, NB_T mtarget_low ,NB_T mtarget_high);
void mullow(NB_T src1, NB_T src2, NB_T mtarget);
/* traget = src*src */
void square(NB_T src, NB_T target);
void squareful(NB_T src,NB_T target);
/* NBmul.cpp end */

/* montgomery algorithm mulmod */
/* target = (src1*src2)%mod (montgomery algorithm) */
int mulmod(NB_T src1, NB_T src2, NB_T target, NB_T mod);
int accmulmod(NB_T src1, NB_T src2, NB_T target, NB_T mod,int r,NB_T u,NB_T rsq);
/* helper function for montgomery algorithm */
int deducersize(NB_T N);
int precomputation(NB_T mod,int r,NB_T u,NB_T rsq);
/* end */
