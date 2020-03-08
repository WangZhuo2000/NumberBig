#include "test/NumberBig/numberbig_test.h"
#include "src/NumberBig/NBpublic.h"
#include "src/helper/helper.h"

void reverse(WORD *ary,int index){
    WORD tmp[index];
    for(int i=0;i<index;i++){
        tmp[i] = ary[index-1-i];
    }
    for(int i=0;i<index;i++){
        ary[i] = tmp[i];
    }
}

void divrem2_test(){
    /*
    a = 0004 302524cbabf838da 5b08806b5c4d8e67 8c1adeec25715b2a 9e7f42f81ddc2388
    b = 0000 ca474345d93dbc6d 51ef6bbbeeae8436 66d1270dbd3dee14 e1623a93671a1de9
    */
    printStr("[+] divrem2 function test ");
    printStr(" <begin divrem2 function test> \n");
    WORD aary[5] = {0x0004,0x302524cbabf838daLL,0x5b08806b5c4d8e67LL,0x8c1adeec25715b2aLL,0x9e7f42f81ddc2388LL};
    WORD bary[5] = {0x0000 ,0xca474345d93dbc6dLL,0x51ef6bbbeeae8436LL,0x66d1270dbd3dee14LL,0xe1623a93671a1de9LL};
    reverse(aary,5);
    reverse(bary,5);
    NB a = NB();
    a.setary(aary,5);
    NB b = NB();
    b.setary(bary,5);
    printNB(&a);
    printNB(&b);
    NB q = NB();
    NB r = NB();
    divrem(&a,&b,&q,&r);
    printNB(&q);
    printNB(&r);
    printStr(" <end divrem2 function test> \n");
}

void divrem_test(){
    NB a = randomNB();
    NB b = randomNB();
    NB q = NB();
    NB r = NB();
    printStr("[+] divrem function test ");
    printStr(" <begin divrem function test> \n");
    printNB(&b);
    printStr("\\\n");
    printNB(&a);
    divrem(&b,&a,&q,&r);
    printStr("quotient:");
    printNB(&q);
    printStr("remainer:");
    printNB(&r);
    printStr(" <end divrem function test> \n");
}

void mod_test(){
    NB a = randomNB();
    NB b = randomNB();
    NB m;
    mod(&a,&b,&m);
    printNB(&a);
    printNB(&b);
    printNB(&m);
}