#include <stdio.h>


unsigned int CalcNext8x(unsigned int x){
    unsigned int mod8 = x % 8;
    return mod8 ? x - mod8 + 8 : x;
}



int main() {
    printf("Hello, World!\n");
    return 0;
}
