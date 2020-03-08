#include "numberbig_test.h"
#include "src/NumberBig/NBpublic.h"
#include "src/helper/helper.h"

void cmp_test(){
    NB a = NB(1);
    NB b = NB(-1);
    if(cmp(&a,&b)!=1){
        printStr("[-] cmp test failed in 1 > -1\n");
    }else if(cmp(&b,&a)!=-1){
        printStr("[-] cmp test failed in -1 < 1\n");
    }else if(cmp(&a,&a)!=0){
        printStr("[-] cmp test failed in 1 = 1\n");
    }else{
        printStr("[+] cmp test successful!\n");
    }
}

void cmpabs_test(){
    NB r = randomNB();
    if(cmp(&r,&r)!=0){
        printStr("[-] cmpabs test failed in ");
        printNB(&r);
    }
    printStr("[+] cmpabs test successful!\n");
}