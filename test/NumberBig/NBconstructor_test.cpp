#include "test/NumberBig/numberbig_test.h"
#include "src/NumberBig/NB.h"
#include "src/helper/helper.h"

void constructor_test()
{
    NB o = NB();
    NB a = NB(0);
    NB b = NB(-1);
    NB c = NB(1);
    printStr("[+] NumberBig constructor test successful !\n");
}
