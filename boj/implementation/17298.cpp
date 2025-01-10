#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int NGE = -1;
    cin >> n;
    vector<int> v(n);
    int head;
    vector<int> check;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        if(NGE==-1||NGE<=v[i]){

            s.push(v[i]);

            NGE = v[i];
            v[i] = -1;
        } else v[i] = NGE;
    }

    for(int i=0;i<n;i++){
        cout << v[i] << ' ';
    }
}