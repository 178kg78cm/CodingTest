#include <stdio.h>

int main(){
    int a, b = 3;
    a = 0;
    switch(a){
        case 0: b = a + b; break;
        case 1: b = a * b; break;
        case 2: b = a - b; break;
    }

    return 0;
}