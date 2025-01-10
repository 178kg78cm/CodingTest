#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int board[100][100] = {0,};

int cheese=0;
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j]==1) cheese++;
        }
    }

    // 0, 0을 기준으로 bfs 돌리자.
    
    int k=0;
    int fin;
    while(cheese){
        k--;
        fin = cheese;
        queue<pair<int,int>> q;
        bool visitied[100][100] = {0,};
        q.push({0,0});
        while(!q.empty()){
            int y,x;
            tie(y,x) = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x+dx[i], ny = y+dy[i];
                if(ny<0||ny>=n||nx<0||nx>=m) continue;
                if(board[ny][nx]==1){

                    board[ny][nx] = k;
                    cheese--;
                    continue;
                }
                if(board[ny][nx] >= k+1 && !visitied[ny][nx]) {
                    visitied[ny][nx]=1;
                    q.push({ny,nx});
                }
            }
        }
    }
    
    cout << -1*k << '\n' << fin;
}