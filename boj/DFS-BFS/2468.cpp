#include <bits/stdc++.h>
using namespace std;
int n;
int board[100][100] = {0,};
bool visitied[100][100] = {0,};
int dx[4]={1,0,-1,0}, dy[4] = {0,1,0,-1};
int h;
void dfs(int y, int x){
    visitied[y][x]=true;
    
    for(int i =0;i<4;i++){
        int nx = x+dx[i], ny = dy[i]+y;
        if(nx>=n||nx<0||ny>=n||ny<0) continue;
        if(board[ny][nx]>=h&&!visitied[ny][nx]){
            dfs(ny,nx);
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    int max = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            if(board[i][j]>max){
                max = board[i][j];
            }
        }
    }
    int max_count = 0;
    for(h=0;h<=max;h++){
        int count = 0;

        memset(visitied,0,sizeof(visitied));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]>=h&&!visitied[i][j]){
                    dfs(i,j);
                    count++;
                }
            }
        }
        if(count > max_count) max_count = count;
    }

    cout << max_count;
    return 0;
}