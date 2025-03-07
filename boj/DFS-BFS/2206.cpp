#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

char mmap[1001][1001];
int visited[1001][1001][2];
int dx[4] = {1,0,-1,0}, dy[4] = {0, 1, 0, -1};
int main(){
    int n,m;
    cin >> n >> m; 
    
    queue<tuple<int,int,int>> q;

    getchar();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mmap[i][j] = getchar()-'0';
        }
        getchar();
    }
    bool broken = 0;
    int y, x;

    q.push({0,0,0});
    visited[0][0][0] = 1;    
    while(!q.empty()){
        tie(y, x, broken) = q.front();
        q.pop();
        if(x == m-1 && y == n-1){
            cout << visited[y][x][broken];
            return 0;
        } 
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            

            if(nx<0 || ny < 0 || nx >= m || ny >= n) continue;
            if(!mmap[ny][nx] && !visited[ny][nx][broken]){
                q.push({ny,nx,broken});
                visited[ny][nx][broken] = visited[y][x][broken] + 1;  
            }else if(mmap[ny][nx] && !broken && !visited[ny][nx][1]){
                // 벽을 하나 부수자
                q.push({ny,nx,1});
                visited[ny][nx][1] = visited[y][x][broken] + 1;  
            }
        }

    }
    cout << -1 << endl;
    return 0;
}