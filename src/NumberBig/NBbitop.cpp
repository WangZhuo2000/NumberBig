#include "src/NumberBig/NB.h"

void NB::lshift(int bitnum){
    /* calculate block num and remain num */
    int blocknum = bitnum/64;
    int remainnum = bitnum%64;
    WORD tmp1 = 0;
    WORD tmp2 = 0;
    /* first step , move the blocknum */
    for(int i=MAX_number_word-1;i>=0;i--){
        if(blocknum+i<=MAX_number_word-1){
            this->val[i+blocknum] = this->val[i];
        }
    }
    for(int i=0;i<blocknum;i++){
        this->val[i] = 0;
    }
    /* second step , move the remainnum */
    for(int i=0;i<MAX_number_word;i++){
        if(remainnum==0){
            tmp1 = 0;
        }else{
            tmp1 = this->val[i]>>(WORDSIZE-remainnum);
        }
        this->val[i] = this->val[i]<<remainnum;
        this->val[i] += tmp2;
        tmp2 = tmp1;
    }

}

void NB::rshift(int bitnum){
    /* calculate block num and remain num */
    int blocknum = bitnum/64;
    int remainnum = bitnum%64;
    WORD tmp1 = 0;
    WORD tmp2 = 0;
    /* first step , move the blocknum */
    for(int i=0;i<MAX_number_word;i++){
        if(i-blocknum>=0){
            this->val[i-blocknum] = this->val[i];
        }
    }
    for(int i=MAX_number_word-1;i>=MAX_number_word-blocknum;i--){
        this->val[i] = 0;
    }
    /* second step , move the remainnum */
    for(int i=MAX_number_word-1;i>=0;i--){
        if(remainnum==0){
            tmp1 = 0;
        }else{
            tmp1 = this->val[i]<<(WORDSIZE-remainnum);
        }
        this->val[i] = this->val[i]>>remainnum;
        this->val[i] += tmp2;
        tmp2 = tmp1;
    }
}
