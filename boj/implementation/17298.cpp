#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n), NGE(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            NGE[i] = -1;
        }
        else{
            while(s.top()<=v[i]){
                s.pop();
                if(s.empty()) {
                    break;
                }
            }
            if(s.empty()){
                NGE[i] = -1;
            }
            else if(s.top()>v[i]){
                NGE[i] = s.top();
            }
            else{
                NGE[i] = -1;
            }
        }
        
        s.push(v[i]);
    }

    for(int i=0;i<n;i++){
        cout << NGE[i] << ' ';
    }

    return 0;
}