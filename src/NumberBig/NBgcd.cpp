#include "src/NumberBig/NBop.h"
#include "src/helper/helper.h"

/* as+bt==gcd(a,b) */
/* 为什么不使用这个是因为其中乘法操作的结果，很有可能会导致溢出，所以不应该使用这个方法 */
void exgcd_schoolbook(NB_T a,NB_T b,NB_T s, NB_T t,NB_T gcd){
    NB r0,r1,r2;
    NB s0,s1,s2;
    NB t0,t1,t2;
    NB q = NB();
    /* assumption a>=b */
    copy(a,&r0);
    copy(b,&r1);
    s0.setone();
    s1.setzero();
    t0.setzero();
    t1.setone();
    while(1){
        //printNB(&s1);
        /* r2 = r0-q*r1 */
        divrem(&r0,&r1,&q,&r2);
        /* judge stop condition */
        if(r2.iszero()){
            break;
        }
        /* s2 = s0-q*s1 */
        mullow(&q,&s1,&s2);
        sub(&s0,&s2,&s2);
        /* t2 = t0-q*t1 */
        mullow(&q,&t1,&t2);
        sub(&t0,&t2,&t2);
        /* alias */
        copy(&r1,&r0);
        copy(&r2,&r1);
        copy(&s1,&s0);
        copy(&s2,&s1);
        copy(&t1,&t0);
        copy(&t2,&t1);
    }
    /* t = t1,s = s1 ,gcd(a,b) = r1 */
    copy(&t1,t);
    copy(&s1,s);
    copy(&r1,gcd);
}

/* using matrix for word size */
/* https://www.wikiwand.com/en/Euclidean_algorithm#/Matrix_method */
/* s*a+t*b==gcd(a,b) */
void exgcd(NB_T a,NB_T b,NB_T s, NB_T t,NB_T gcd){
    int swap = cmp(a,b);
    /* assumpint a>b */
    NB r0,r1,r2;
    /* M = [[m1,m2],[m3,m4]] */
    NB m1,m2,m3,m4;/* matrix M */
    NB m1t,m2t,m3t,m4t;
    NB q = NB();
    if(swap>=0){
        copy(a,&r0);
        copy(b,&r1);
    }else{
        copy(b,&r0);
        copy(a,&r1);
    }
    m1.setone();
    m2.setzero();
    m3.setzero();
    m4.setone();
    int index = 0;
    while(1){
        /* judge stop condition */
        printNB(&r1);
        if(r1.iszero()){
            break;
        }
        divrem(&r0,&r1,&q,&r2);
        /* update matrix M */
        /* m1 = (m1*q)+m2 */ /* m2 = m1 */ /* m3 = m3*q+m4 */ /* m4 = m3 */
        copy(&m1,&m2t);
        mullow(&m1,&q,&m1);
        add(&m1,&m2,&m1t);

        copy(&m3,&m4t);
        mullow(&m3,&q,&m3);
        add(&m3,&m4,&m3t);
        /* alias copy */
        copy(&r1,&r0);
        copy(&r2,&r1);
        copy(&m1t,&m1);
        copy(&m2t,&m2);
        copy(&m3t,&m3);
        copy(&m4t,&m4);
        index += 1;
    }
    if(index%2==0){
        m2.setsig(SIG_OPPSITE(m2.getsig()));
    }else{
        m4.setsig(SIG_OPPSITE(m4.getsig()));
    }
    if(swap>=0){
        copy(&m4,s);
        copy(&m2,t);
    }else{
        copy(&m4,t);
        copy(&m2,s);
    }
    copy(&r0,gcd);
}

void gcd(NB_T a,NB_T b,NB_T gcd){
    NB s;
    NB t;
    exgcd(a,b,&s,&t,gcd);
}
