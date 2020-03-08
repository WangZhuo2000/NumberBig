#include "src/Word/word_t.h"
#include "src/NumberBig/NB.h"
#include "test/Word/word_test.h"
#include "test/NumberBig/numberbig_test.h"

int main(){
    word_t_test();
    constructor_test();
    onesig_test();
    setary_test();
    rshift_test();
    lshift_test();
    cmp_test();
    cmpabs_test();
    copy_test(); 
    add_test(); 
    sub_test(); 
    sig_test(); 
    oneab_test();
    mulful_test();
    mullow_test();
    divrem_test();
    divrem2_test();
    mod_test();
    exgcd_test();
    exgcd2_test();
    return 0;
}