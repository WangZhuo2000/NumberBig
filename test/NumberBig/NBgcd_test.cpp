#include "src/NumberBig/NBpublic.h"
#include "test/NumberBig/numberbig_test.h"
#include "src/helper/helper.h"

/* 写一个python脚本进行测试 ！！！！ */
void exgcd_test(){
    NB b = randomNB();
    NB a = randomNB();
    a.setval(0,MAX_number_word-1);
    b.setval(0,MAX_number_word-1);
    NB s,t,gcd;
    printStr("[+] exgcd function test...\n");
    printStr(" <begin exgcd test> \n");
    printNB(&a);
    printNB(&b);
    exgcd(&a,&b,&s,&t,&gcd);
    printNB(&s);
    printNB(&t);
    printNB(&gcd);
    printStr(" <end exgcd test> \n");
}

void exgcd2_test(){
    NB b = randomNB();
    NB a = randomNB();
    NB s,t,gcd;
    printStr("[+] exgcd 2 function test...\n");
    printStr(" <begin 2 exgcd test> \n");
    printNB(&a);
    printNB(&b);
    exgcd(&a,&b,&s,&t,&gcd);
    printNB(&s);
    printNB(&t);
    printNB(&gcd);
    printStr(" <end 2 exgcd test> \n");
}

/*
def rlog(a:int):
    with open("r_output.txt","a") as f:
        f.write(str(a.bit_length()))
        f.write(":")
        f.write(hex(a))
        f.write("\n")
def tlog(a:int):
    with open("t_output.txt","a") as f:
        f.write(str(a.bit_length()))
        f.write(":")
        f.write(hex(a))
        f.write("\n")
def slog(a:int):
    with open("s_output.txt","a") as f:
        f.write(str(a.bit_length()))
        f.write(":")
        f.write(hex(a))
        f.write("\n")
def midlog(a:int):
    with open("mid_output.txt","a") as f:
        f.write(str(a.bit_length()))
        f.write(":")
        f.write(hex(a))
        f.write("\n")

def mlog(a:int,index:int):
    with open("m"+str(index)+"_output.txt","a") as f:
        f.write(str(a.bit_length()))
        f.write(":")
        f.write(hex(a))
        f.write("\n")

def clean_mr():
    files = ["r_output.txt"]
    for i in range(4):
        files.append("m"+str(i+1)+"_output.txt")
    for file in files:
        with open(file,"w") as f:
            f.truncate()
def clean():
    files = ["r_output.txt","t_output.txt","s_output.txt","mid_output.txt"]
    for file in files:
        with open(file,"w") as f:
            f.truncate()

def ext_euclid(a, b):
    clean()
    old_s,s=1,0
    slog(old_s)
    old_t,t=0,1
    tlog(old_t)
    old_r,r=a,b
    rlog(old_r)
    if b == 0:
        return 1, 0, a
    else:
        while(r!=0):
            q=old_r//r
            old_r,r=r,old_r-q*r
            rlog(old_r)
            old_s,s=s,old_s-q*s
            slog(old_s)
            midlog(q*s)
            old_t,t=t,old_t-q*t
            tlog(old_t)
            midlog(q*t)
    return old_s, old_t, old_r

def matrix_gcd(a,b):
    clean_mr()
    r0=a
    r1=b
    m1 = 1
    m2 = 0
    m3 = 0
    m4 = 1
    index = 0
    while(r1!=0):
        index += 1
        q = r0//r1
        r0,r1 = r1,r0-q*r1
        rlog(r0)
        m1,m2 = m1*q+m2,m1
        mlog(m1,1)
        mlog(m2,2)
        m3,m4 = m3*q+m4,m3
        mlog(m3,3)
        mlog(m4,4)
    if index%2==0:
        m2 = -m2
    else:
        m4 = -m4
    return m4,m2,r0


if __name__=='__main__':
    a = 0x0000000000000000260d8c4a73d4d3c465968c1c46263dec6e534cde1a0dde3278b5e77675486e47312167ad631b64d40f819e7f57c7d42d61e74ea3597b4d84
    b = 0x00000000000000001816f8c437df223369e7f3e52a6de8067dff9d09007543422a31b62d1849c29b634c574c24e99dd75551b9f324f6ab8e49d0feac4bee5a5b
    s,t,r = matrix_gcd(a,b)
    #s,t,r = ext_euclid(a,b)
    print(s*a+t*b==r)
    print(r)
*/