#include "src/NumberBig/NB.h"
#include "src/NumberBig/NBop.h"

/*  a>b return 1 
    a<b return -1
    a=b return 0
*/
int cmp(NB_T a, NB_T b){
    int tmp,tmp2;
    tmp2 = cmpabs(a,b);
    if(tmp2==0){
        return 0;
    }
    tmp = a->getsig()==POS?1:-1;
    if(a->getsig()!=b->getsig()){
        return tmp;
    }
    return tmp*tmp2;
}

/* abs(a)>abs(b) return 1
   abs(a)<abs(b) return -1
   abs(a)=abs(b) return 0
*/

int cmpabs(NB_T a, NB_T b){
    for (int i = MAX_number_word - 1; i >= 0; i--)
    {
        if (a->getval(i) > b->getval(i))
        {
            return 1;
        }
        else if (a->getval(i) < b->getval(i))
        {
            return -1;
        }
        else{
            continue;
        }
    }
    return 0;
}
