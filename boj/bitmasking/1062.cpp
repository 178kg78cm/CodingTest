#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
vector<int> words;  
int maxWord = 0; 
bool visited[26] = {false,};

void dfs(int idx, int selected, int learnedMask) {
    if(selected == k - 5) {
        int count = 0;
        for (int wordMask : words) {
            if ((wordMask & learnedMask) == wordMask)
                count++;
        }
        maxWord = max(maxWord, count);
        return;
    }
    for (int i = idx; i < 26; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i + 1, selected + 1, learnedMask | (1 << i));
            visited[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    if (k < 5) {
        cout << 0;
        return 0;
    }
    
    int learnedMask = 0;
    vector<char> essentials = {'a', 'n', 't', 'i', 'c'};
    for (char ch : essentials) {
        int pos = ch - 'a';
        visited[pos] = true;
        learnedMask |= (1 << pos);
    }
    
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        int mask = 0;
        for (int j = 4; j < s.size() - 4; j++){
            mask |= (1 << (s[j] - 'a'));
        }
        words.push_back(mask);
    }
    
    dfs(0, 0, learnedMask);
    
    cout << maxWord;
    return 0;
}
