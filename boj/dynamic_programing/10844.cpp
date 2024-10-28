#include <iostream>

using namespace std;

int main(){
    int mod = 1000000000;
    int number[101][10] = { 0,};
    int N;
    int result = 0;

    cin >> N;
    for(int i=1;i<10;i++)
        number[0][i]=1;

    for(int n=1;n<N;n++){
        for(int i=0;i<10;i++){
            if(i!=0) number[n][i]+=number[n-1][i-1];
            if(i!=9) number[n][i]+=number[n-1][i+1];
            number[n][i]%=mod;
        }
    }
    for(int i=0;i<10;i++)
        result = (result + number[N-1][i]) % mod;
    cout << result;

    return 0;
}

/*
    12 23 34 45 56 67 78 89  
    10 21 32 43 54 65 76 87 98 
    */