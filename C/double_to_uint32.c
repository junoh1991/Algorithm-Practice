#include <stdio.h>
#include <stdint.h>


uint32_t getUint1(double input){
    uint32_t* p;

    p = (uint32_t*) &input;
    return *p;
}

uint32_t getUint2(double input){
    uint32_t* p;

    p = (uint32_t*) &input;
    p++;
    return *p;
}

double getDouble(uint32_t r1, uint32_t r2){
    uint32_t* p;
    double* val;

    p = (double*) &r1;
    p++;
    p = (double*) &r2;
    p--;

    val = (double*) p;
    return *val;
}


int main(){

    double input = 12345.18;

    uint32_t r1 = getUint1(input);
    uint32_t r2 = getUint2(input);

    double ans = getDouble(r1, r2);
    printf("%.2f\n", ans);

    
}
