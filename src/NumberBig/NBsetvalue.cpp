#include "src/NumberBig/NB.h"

sig_t NB::getsig(){
    return this->sig;
}

void NB::setsig(sig_t s){
    this->sig = s;
}

void NB::setpos(){
    this->sig = POS;
}

void NB::setneg(){
    this->sig = NEG;
}

void NB::setzero()
{
    for (int i = 0; i < MAX_number_word; i++)
    {
        this->val[i] = 0;
    }
    sig = POS;
}

/* set one method for current NB */
void NB::setone()
{
    val[0] = WORD(1);
    for (int i = 1; i < MAX_number_word; i++)
    {
        val[i] = 0;
    }
    sig = POS;
}

/* set int value to NB, need : sizeof(int)<=sizeof(uint64_t) */
void NB::setint(int x)
{
    if (x >= 0)
    {
        sig = POS;
        val[0] = WORD(x);
    }
    else
    {
        sig = NEG;
        val[0] = WORD(-x);
    }
    for (int i = 1; i < MAX_number_word; i++)
    {
        val[i] = 0;
    }
}

int NB::setary(WORD_T x,int arynum){
    if(arynum>MAX_number_word||arynum<=0){
        return 0;
    }
    sig = POS;
    for(int i=0;i<arynum;i++){
        val[i] = x[i];
    }
    for(int i=arynum;i<MAX_number_word;i++){
        val[i] = WORD(0);
    }
    return 1;
}


void NB::abs(){
    this->sig = POS;
}

/* if this is zero return 1 otherwise return 0; */
int NB::iszero(){
    for(int i=0;i<MAX_number_word;i++){
        if(this->val[i]!=0){
            return 0;
        }
    }
    return 1;
}

int NB::isone(){
    if(this->getsig()!=POS){
        return 0;
    }
    if(this->getval(0)!=1){
        return 0;
    }
    for(int i=1;i<MAX_number_word;i++){
        if(this->val[i]!=0){
            return 0;
        }
    }
    return 1;
}

void NB::getmax(){
    for(int i=0;i<MAX_number_word;i++){
        this->val[i] = WORDMAX;
    }
    this->sig = POS;
}

WORD NB::getval(int index){
    if(index<0||index>=MAX_number_word){
        throw "memory access error!";
    }
    return this->val[index];
}

void NB::setval(WORD v,int index){
    if(index<0||index>=MAX_number_word){
        throw "memory access error!";
    }
    this->val[index] = v;
}
