#include "test/NumberBig/numberbig_test.h"
#include "src/NumberBig/NBpublic.h"
#include "src/helper/helper.h"

void copy_test(){
    NB a = randomNB();
    NB b;
    copy(&a,&b);
    if(cmp(&a,&b)!=0){
        printStr("[-] function copy test failed!\n");
    }
    printStr("[-] function copy test successful!\n");
}

void add_test(){
    NB a = randomNB();
    NB b = randomNB();
    NB c = NB();
    add(&a,&b,&c);
    printStr("[+] add test begin\n");
    printStr("< add test begin >\n");
    printNB(&a);
    printStr("+\n");
    printNB(&b);
    printStr("=\n");
    printNB(&c);
    printStr("< add test end >\n");
}

void sub_test(){
    NB a = randomNB();
    NB b = randomNB();
    NB c = NB();
    sub(&a,&b,&c);
    printStr("[+] sub test begin\n");
    printStr("< sub test begin >\n");
    printNB(&a);
    printStr("-\n");
    printNB(&b);
    printStr("=\n");
    printNB(&c);
    printStr("< sub test end >\n");
}

void sig_test(){
    NB a = NB(1);
    NB b = NB(-1);
    NB c = NB(2);
    NB d = NB();
    sub(&a,&b,&d);
    if(cmp(&c,&d)!=0){
        printStr("[-] sig test failed!\n");
        return ;
    }
    sub(&a,&c,&d);
    if(cmp(&b,&d)!=0){
        printStr("[-] sig test failed!\n");
        return ;
    }
    printStr("[+] sig test successful!\n");
}

void oneab_test(){
    NB a = randomNB();
    NB b = NB();
    inc(&a,&b);
    if(cmp(&a,&b)!=-1){
        printStr("[-] failed in inc funciton test!\n");
        return ;
    }
    dec(&b,&b);
    if(cmp(&a,&b)!=0){
        printStr("[-] failed in dec funciton test!\n");
        return ;
    }
    printStr("[+] successful in inc funciton test!\n");
    printStr("[+] successful in dec funciton test!\n");
}



