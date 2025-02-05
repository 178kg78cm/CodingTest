/*CPTI*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int n, m;
/*
int bool2int(string s){
    int temp = 0;
    for(int i=0;i<m;i++){
        if((s[i]-'0')){
            temp+= (s[i]-'0') << i;
        }
    }
    return temp;
}
*/
int toBitmask(const string& s) {
    int mask = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == '1') {
            mask |= (1 << i); 
        }
    }
    return mask;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    string s;
    unordered_map<int,int> mmap;
    for(int i=0;i<n;i++){
        cin >> s;
        mmap[toBitmask(s)]++;
    }
    vector<int> keys;  
    for (const auto& kv : mmap) {
        keys.push_back(kv.first);
    }
    int answer = 0;
    for (int i = 0; i < keys.size(); i++) {
        for (int j = i; j < keys.size(); j++) {
            int diff = __builtin_popcount(keys[i] ^ keys[j]);

            if (diff <= 2) {
                if (i == j) {
                    answer += (mmap[keys[i]] * (mmap[keys[i]] - 1)) / 2;
                } else {
                    answer += mmap[keys[i]] * mmap[keys[j]];
                }
            }
        }
    } 
    cout << answer;
    return 0;
}
