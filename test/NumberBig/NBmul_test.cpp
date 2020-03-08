#include "src/helper/helper.h"
#include "src/NumberBig/NBpublic.h"
#include "test/NumberBig/numberbig_test.h"

void mulful_test(){
    NB a = randomNB();
    NB b = randomNB();
    NB c = NB();
    NB d = NB();
    mulful(&a,&b,&c,&d);
    printStr("[+] test mulful function \n");
    printStr("<begin mulful> \n");
    printNB(&a);
    printStr("*\n");
    printNB(&b);
    printStr("=\n");
    printNB(&c);
    printStr("||\n");
    printNB(&d);
    printStr("<end mulful> \n");
}

void mullow_test(){
    NB a = randomNB();
    NB b = randomNB();
    NB c = NB();
    NB d = NB();
    mullow(&a,&b,&c);
    printStr("[+] test mullow function \n");
    printStr("<begin mullow> \n");
    printNB(&a);
    printStr("*\n");
    printNB(&b);
    printStr("=\n");
    printNB(&c);
    printStr("<end mullow> \n");
}
