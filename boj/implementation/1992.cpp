#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    bool tree[64][64] = {0,};

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<n;j++){
            tree[i][j]=s[j] - '0';
        }
    }
    int t=n/2;
    int posx[4]={0,t,0,t}, posy[4]={0,0,t,t};
    for(int k=0;k<4;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int nx=j+posx[k], ny=i+posy[k];
                tree[i][j]
            }
        } // 구역 하나 검사사

    }
    
}