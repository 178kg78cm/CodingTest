#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    string line;
    int i=0;
    while(1){
        getline(cin, line);
        if(line == ".") break;
        stack<char> s;
        // cout << ++i << '-' << line << '\n';
        for(auto c : line){
            if(!(c == '(' || c == ')' || c == '[' || c == ']')) continue;
            if(s.empty()){
                s.push(c);
            }else {
                if(s.top()=='('){
                    if(c==')'){
                        s.pop();
                    } else s.push(c);
                }else if(s.top()=='['){
                    if(c==']'){
                        s.pop();
                    } else s.push(c);
                }else break;;
            }
        }
        if(!s.empty()) cout << "no\n";
        else cout << "yes\n";
    }
    return 0;
}