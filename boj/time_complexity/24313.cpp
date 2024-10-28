#include <iostream>
using namespace std;
int main(){
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if((a*n+b) > c*n)
        cout << 0;
    else if(a>c)
        cout << 0;
    else
        cout << 1;
    return 0;
}
