#include "src/Word/word_t.h"
#include "src/helper/helper.h"
#include "word_test.h"

void word_t_test(){
    #ifndef WORD
    throw "WORD type define failed!";
    #endif
    if(WORDSIZE != 2*HALFWORDSIZE){
        throw "wordsize define failed!";
    }
    printStr("[+] Word test successful !\n");
}