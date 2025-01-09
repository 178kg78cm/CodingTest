#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string line;
        cin >> line;

        stack<char> s;
        for(auto c : line){
            if(s.empty()){
                s.push(c);
            }else if(s.top()=='('){
                if(c==')'){
                    s.pop();
                }else s.push(c);
            }
        }
        if(!s.empty()) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}