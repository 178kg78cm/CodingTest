#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int des = 600;
    while(n){
        string s=to_string(des);
        if(s.find("666")!=string::npos){
            n--;
        }
        des++;
    }

    cout << des - 1;
    return 0;
}