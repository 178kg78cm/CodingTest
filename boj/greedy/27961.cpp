#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n;
    cin >> n;
    long long answer=0;
    if(n==0) {cout << 0;return 0;}
    if(n==1) {cout << 1;return 0;}
    n--;
    while(n>=2){
        n>>=1;
        answer++;
    }
    cout << answer + 2;
    return 0;
}