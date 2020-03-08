#pragma once

#include "src/Word/word_t.h"
#include "src/NumberBig/NBconfig.h"

/* 定义类NumberBig和对应的指针类型NB_T*/
class NB;
typedef NB *NB_T;
/* 定义符号枚举类型 */
enum sig_t : uint8_t
{
    POS = 0,
    NEG = 1
};
/* the sig value oppsite */
#define SIG_OPPSITE(x) x == POS ? NEG : POS
/* 声明类中的方法 */
class NB
{
private:
    sig_t sig = POS;
    WORD val[MAX_number_word];
public:
    /* implemented in consturctor.cpp */
    NB();
    NB(int x);
    ~NB();
    /* constructor.cpp end */

    /* implemented in setvalue.cpp */
    /* pos zero is equal to neg zero in this implementation */
    sig_t getsig();
    void setsig(sig_t s);
    void setpos(); /* set sig to pos */
    void setneg(); /* set sig to neg */
    void setzero();     /* set NB to 0 ,return 1 always*/
    void setone();      /* set NB to 1 ,return 1 always*/
    void setint(int x); /* set NB to x */
    int setary(WORD_T x,int arynum); /* set NB to first x-ary , the size of x-ary need be bigger than Max len */
    void abs();         /* set the sign to positive */
    int iszero(); /* return 1 if the val is zero ,otherwise return 0 */
    int isone(); /* return 1 if the val is one ,otherwise return 0; */
    void getmax(); /* return the max value in numberbig class */
    WORD getval(int index); /* throw exception if fail ! */
    void setval(WORD v,int index); /* throw exception if fail ! */
    /*  setvalue.cpp end */

    /* implemented in  bitop.cpp */
    void lshift(int bitnum);
    void rshift(int bitnum);
    /* bitop.cpp end */
};

