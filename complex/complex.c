#include <stdio.h>


struct complex{
    int real;
    int im;
};

struct complex sum(struct complex s1,struct complex s2){

    struct complex result;

    result.real = s1.real + s2.real;
    result.im   = s1.im + s2.im;
    return result;

}

int main(){
    struct complex s1,s2,result;
    s1.real = 10;
    s2.real = 120;
    s1.im = 100;
    s2.im = 20;

    result = sum(s1,s2);
    printf("The result is %d + %d i",result.real,result.im);
}
