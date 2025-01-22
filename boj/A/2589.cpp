#include<bits/stdc++.h>
using namespace std;
int w, h;
char mmap[50][50];
bool visitied[50][50];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int land = 0;
int main(){
    cin >> w >> h;
    for(int i=0;i<h;i++){
        string s;
        cin >> s;
        for(int j=0;j<w;j++){
            mmap[i][j] = s[j];
            if(s[j]=='L') land++;
        }
    }

    
}