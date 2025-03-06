#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> mmap(n + 1, vector<bool>(m + 1, false));
    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
    int dx[4] = {1,0,-1,0}, dy[4] = {0, 1, 0, -1};
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
    visited[0][0] = 1;    
    while(!q.empty()){
        tie(y, x, broken) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(ny == n-1 && nx == m-1){
                cout << visited[y][x] + 1;
                return 0;
            } 

            if(nx<0 || ny < 0 || nx >= m || ny >= n) continue;
            if(mmap[ny][nx] == true){
                // 벽을 하나 부수자
                if(broken==1) continue;
                q.push({y,x,1});
            }else{
                q.push({y,x,0});
            }
            visited[ny][nx] = visited[y][x] + 1;  
        }

    }
    cout << -1 << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << mmap[i][j];
        }
        putchar('\n');
    }
    return 0;

    
}