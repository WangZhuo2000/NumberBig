#include "src/NumberBig/NB.h"

/* NumberBig 的构造函数 */
NB::NB()
{
    for (int i = 0; i < MAX_number_word; i++)
    {
        NB::val[i] = 0;
    }
    sig = POS;
}

/* NumberBig 使用x构造一个大数 */
NB::NB(int x)
{
    if (x >= 0)
    {
        sig = POS;
        val[0] = x;
    }
    else
    {
        sig = NEG;
        val[0] = -x;
    }
    for (int i = 1; i < MAX_number_word; i++)
    {
        val[i] = 0;
    }
}

/* 析构函数什么都没做 */
NB::~NB() {}
