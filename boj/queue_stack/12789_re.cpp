#include <stack>
#include <iostream>

using namespace std; 

int main(){
    stack<int> b;
    int n, m=1, k;
    cin >> n;

    while(n--){
        cin >> k;
        if(k==m) m++;
        else b.push(k);

        while(!b.empty()&&b.top()==m){
            m++;
            b.pop();
        }
    }

    if(b.empty()) cout << "Nice\n";
    else cout << "Sad\n";

    return 0;
}