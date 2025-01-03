#include <iostream>
using namespace std;
unsigned long long a, b, c, answer = 1;

int modi(int n){
    if(b==n) return a%c;
    return modi(n+1)*a%c;
}
int main(){
    cin >> a >> b >> c;
    cout << modi(1);
    return 0;
}