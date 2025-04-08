#include <iostream>
using namespace std;
int count = 0;
int N, r, c;

void Z(int y, int x, int n){
    if(n==0){
        cout << count;
        return;
    }
    int mid = 1 << (n-1); // 비트 연산 쓰는거 개 굿
    int x_mid = x + mid;
    int y_mid = y + mid;
    mid = mid*mid; 

    if(c < x_mid){
        if(r < y_mid){ // 1사분면
            Z(y,x,n-1);
        }
        else{ // 3사분면
            count += mid * 2;    
            Z(y_mid, x, n-1);
        }
    }
    else{
        if(r < y_mid){ // 2사분면
            count += mid;    
            Z(y, x_mid, n-1);
        }
        else{
            count += mid * 3;    
            Z(y_mid, x_mid, n-1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> r >> c;
    Z(0,0,N);

    return 0;
}