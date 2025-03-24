#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s, s2;
    cin >> s;
    cin >> s2;
    int answer = 0;
    for(int i=0;i<n;i++){
        if(s[i] != s2[i]){
            if(i!=0)
                s[i-1]=='1' ? s[i-1]='0' : s[i-1]='1';
                
            s[i]=='1' ? s[i]='0' : s[i]='1';
            
            if(i!=n-1)
                s[i+1]=='1' ? s[i+1]='0' : s[i+1]='1';
            answer++;
        }
    }

    for(int i=0;i<n;i++){
        if(s[i]!=s2[i]){
            cout << -1;
            return 0;
        }
    }
    cout << answer;
    return 0;
}