#include "src/helper/helper.h"
#include <stdlib.h>

NB randomNB(){
    int tmp1,tmp2;
    WORD t[MAX_number_word];
    if(HALFWORDSIZE!=sizeof(int)*BYTESIZE){
        printStr("random NB needed be rewriten !\n");
    }
    for(int i=0;i<MAX_number_word;i++){
        tmp1 = random();
        tmp2 = random();
        t[i] = (((WORD)tmp1)<<HALFWORDSIZE)+(WORD)tmp2;
    }
    NB b = NB();
    b.setary(t,MAX_number_word);
    return b;
}