#include "test/NumberBig/numberbig_test.h"
#include "src/NumberBig/NB.h"
#include "src/helper/helper.h"

void lshift_test(){
    printStr("[+] lshift operation test\n");
    printStr("< lshift operation Begin >\n");
    NB a = randomNB();
    printStr("random generate a NB value\n");
    printNB(&a);
    int bit = 122;
    a.lshift(bit);
    printStr("lshift %d bit value \n",bit);
    printNB(&a);
    printStr("< lshift operation end >\n");
}

void rshift_test(){
    printStr("[+] rshift operation test\n");
    printStr("< rshift operation Begin >\n");
    NB a = randomNB();
    printStr("random generate a NB value\n");
    printNB(&a);
    int bit = 122;
    a.rshift(bit);
    printStr("rshift %d bit value \n",bit);
    printNB(&a);
    printStr("< rshift operation end >\n");
}