#include <iostream>
#include <string>

using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    int alpabet[26] = {0,};
    for(int i=0;i<s.length();i++)
        alpabet[s[i]-'a']++;

    for(int i=0;i<26;i++)
        cout << alpabet[i] << " ";

    return 0;
}