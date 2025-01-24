#include<bits/stdc++.h>
using namespace std;
int w, h;
char mmap[50][50];
int visitied[50][50] = {0,};
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
set<pair<int,int>> land;
void bfs(){
    for(int i=0;i<){

    }
}
int main(){
    cin >> w >> h;
    for(int i=0;i<h;i++){
        string s;
        cin >> s;
        for(int j=0;j<w;j++){
            mmap[i][j] = s[j];
            if(s[j]=='L') land.insert({i,j});
        }
    }
    
    queue<pair<pair<int,int>, int>> q;

    while(!q.empty()){
        int dist, x, y;
        tie(dist, x, y) = 
        for(int i=0;i<4;i++){
            int ny = y+dy[i], nx = x+dx[i];

            if(visitied==0){
                q.
            }
        }
    }
}