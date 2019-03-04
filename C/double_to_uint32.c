#include <stdio.h>
#include <stdint.h>


void getUint1(double input, uint32_t* arr){
    uint32_t* p;

    p = (uint32_t*) &input;
    arr[0] = *p;
    arr[1] = *(p+1);
}

double getDouble(uint32_t r1, uint32_t r2){
    uint32_t* p;

    p =  &r1;
    p++;
    p =  &r2;
    p--;

    return *(double*) (p);
}


int main(){

    double input = 12345.67;

    uint32_t arr[2];

    getUint1(input, arr);

    double ans = getDouble(arr[0], arr[1]);
    printf("%.2f\n", ans);
}
