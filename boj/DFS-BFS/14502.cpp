#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int board[8][8] = {0,};
bool visited[8][8] = {0,};
int vaild = 0;
int safe = 0;
int answer = 0;
int n, m;
void bfs(int basey,int basex){
    queue<pair<int,int>> q;
    q.push({basey,basex});
    visited[basey][basex] = true;
    while(!q.empty()){
        int x, y;
        tie(y,x) = q.front();
        for(int i=0;i<4;i++){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny<0||ny>=n||nx<0||nx>=m) continue;
            if(board[ny][nx]!=0||visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            q.push({ny,nx});
            safe--;
        }
        q.pop();
    }
    
}
int main(){
    cin >> n >> m; 
    vector<pair<int,int>> virus, wall;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j]==2){
                virus.push_back({i,j});
            } else if(board[i][j]==0){
                vaild++;
                wall.push_back({i,j});
            }
        }
    } 
    for(int i=0;i<wall.size()-2;i++){
        for(int j=i+1;j<wall.size()-1;j++){
            for(int k=j+1;k<wall.size();k++){
                auto it1=wall[i];
                auto it2=wall[j];
                auto it3=wall[k];
                board[it1.first][it1.second] = 1;
                board[it2.first][it2.second] = 1;
                board[it3.first][it3.second] = 1;
                safe = vaild-3;

                for(auto it : virus){
                    int x, y;
                    tie(y,x) = it;
                    bfs(y,x);
                }
                if(answer < safe){
                    answer = safe;
                }
                // memset(visited, 0, sizeof(visited));
                fill(&visited[0][0],&visited[7][7]+1,0);
                board[it1.first][it1.second] = 0;
                board[it2.first][it2.second] = 0;
                board[it3.first][it3.second] = 0;

            }
        }
    }
    
    cout << answer;
    return 0;
}