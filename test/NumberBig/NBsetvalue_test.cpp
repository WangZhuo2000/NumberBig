#include "test/NumberBig/numberbig_test.h"
#include "src/NumberBig/NB.h"
#include "src/helper/helper.h"

void onesig_test(){
    NB a = NB(1);
    if(a.getsig()!=POS){
        printStr("[-] sig test fail in setone method\n");
        return;
    }
    a.setneg();
    if(a.getsig()!=NEG){
        printStr("[-] sig test fail in setneg method\n");
        return ;
    }
    a.abs();
    if(a.getsig()!=POS){
        printStr("[-] sig test fail in abs method\n");
        return;
    }
    printStr("[+] one is positive sig successful!\n");
}

void setary_test(){
    NB a = NB(0);
    WORD b[9] = {0};
    if(a.setary(b,8)!=1){
        printStr("[-] setary function test fail\n");
        return ;
    }
    if(a.setary(b,9)!=0){
        printStr("[-] setary function test fail\n");
        return ;
    }
    printStr("[+] setary function test successful !\n");
}
