#include "src/helper/helper.h"

void printNB(NB_T x)
{
    if (x->getsig() == POS)
    {
        printStr("+");
    }
    else
    {
        printStr("-");
    }
    printStr("(");
    for (int i = MAX_number_word-1; i >= 0; i--)
    {
        printStr("%016lx",x->getval(i));
    }
    printStr(")\n");
}