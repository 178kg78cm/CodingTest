#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
typedef struct point{
    int x;
    int y;
    int k;
}Point;

bool board[1001][1001];
int visited[1001][1001][11];
int dx[4] = {1,0,-1,0}, dy[4] = {0, 1, 0, -1};
int main(void){
    int n,m,k;
    cin >> n >> m >> k;
    
    cin.get();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            board[i][j] = cin.get() - '0';
        }
        cin.get();
    }
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    int answer = 1e9;
    visited[0][0][0] = 1;
    while(!q.empty()){
        int x, y, depth;
        tie(y,x,depth) = q.front();
        q.pop();
        if(y==n-1&&x==m-1){
            cout << visited[y][x][depth];
            return 0;
        }
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            int ndepth = depth;
            if(ny >= n || nx >= m || ny < 0 || nx < 0) continue;
            if(board[ny][nx]){ // 벽이 있을 때,
                if(depth + 1 > k) continue; // 부술 횟수가 남아있지 않으면 continue
                else ndepth++;
            }
            if(visited[ny][nx][ndepth]) continue;
            visited[ny][nx][ndepth] = visited[y][x][depth] + 1;
            q.push({ny,nx,ndepth});
        }
    }
    cout << -1;
    return 0;
}