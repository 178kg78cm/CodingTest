#include<bits/stdc++.h>

using namespace std;
bool board[50][50] = {0,};
bool visitied[50][50] = {0,};
int dx[4]={1,0,-1,0}, dy[4] = {0,1,0,-1};
int m, n, k;

void dfs(int x, int y){
    visitied[y][x] = 1;
    int i = 0;
    for(i=0;i<4;i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(nx<0||nx>=m||ny<0||ny>=n) continue;
        if(board[ny][nx] && !visitied[ny][nx])
            dfs(nx,ny);
    }
}
int main(){
    int t;
    
    cin >> t;
    while(t--) {
        memset(board,0,sizeof(board));
        memset(visitied,0,sizeof(visitied));
        int count = 0;
        cin >> m >> n >> k;
        for(int i=0;i<k;i++){
            int x, y;
            cin >> x >> y;
            board[y][x]=1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visitied[i][j]&&board[i][j]){
                    count++;
                    dfs(j,i);
                } 
            }
        }
        cout << count << '\n';
    }
    return 0;
}