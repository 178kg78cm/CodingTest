#include <iostream>
#include <queue>
using namespace std;
bool mmap[1001][1001];
int visited[1001][1001][11];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

typedef struct {
    int y;
    int x;
    bool day;
    int depth;
    int stay;
} Point;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    cin.get();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mmap[i][j] = cin.get() - '0';
        }
        cin.get();
    }

    queue<Point> q;
    q.push({0,0,1,0,0});
    visited[0][0][0] = 1;
    int depth = 0;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        bool day = q.front().day;
        int depth = q.front().depth;
        int stay = q.front().stay;
        q.pop();
        if(x == m-1 && y == n-1) {
            cout << visited[y][x][depth];
            // cout << depth << ' ' << visited[y][x][depth];
            return 0;
        }
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny<0||nx<0||ny>=n||nx>=m) continue;

            if(mmap[ny][nx] == 1){ // 벽일 때
                if(visited[ny][nx][depth+1] > 0) continue;
                if(depth == k) continue;
                else if(day == 0){
                    q.push((Point){y,x,!day,depth,1});
                }else{ // 낮이고 벽있을때
                    int add = 1;
                    if(stay == 1) add++;
                    q.push((Point){ny,nx,!day,depth+1,0});
                    visited[ny][nx][depth+1] = visited[y][x][depth] + add;
                }

            }
            else{ // 벽 아닐 때
                if(visited[ny][nx][depth] != 0) continue;
                q.push((Point){ny,nx,!day,depth,0});
                visited[ny][nx][depth] = visited[y][x][depth] + 1;
            } // 낮 밤 고려해야함.
        }
    }
    cout << -1;
    return 0;
}