#include <iostream>
#include <string>

using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;
    int slen = s.length();
    bool pelin = 1;
    for(int i=0;i<=slen/2;i++){
        if(s[i] != s[slen-1-i]){
            pelin = 0;
            break;
        }
    }
    cout << pelin;
    return 0;
}