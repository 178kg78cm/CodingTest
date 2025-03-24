#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int board[21][21];
int sharkSize = 2;
int eaten = 0;
int totalTime = 0;
int sx, sy;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

struct Fish {
    int dist;
    int y;
    int x;
};

bool cmp(const Fish &a, const Fish &b) {
    if(a.dist == b.dist) {
        if(a.y == b.y)
            return a.x < b.x;
        return a.y < b.y;
    }
    return a.dist < b.dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            if(board[i][j] == 9){
                sy = i;
                sx = j;
                board[i][j] = 0; // 시작 위치
            }
        }
    }
    
    while (true) {
        vector<vector<int>> dist(N, vector<int>(N, -1));
        queue<pair<int, int>> q;
        q.push({sy, sx});
        dist[sy][sx] = 0;
        vector<Fish> fishv;
        
        // BFS 탐색으로 먹을 수 있는 물고기를 찾음
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int cy = cur.first, cx = cur.second;
            for (int i = 0; i < 4; i++){
                int ny = cy + dy[i], nx = cx + dx[i];
                if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if(dist[ny][nx] != -1) continue;
                if(board[ny][nx] > sharkSize) continue;  // 지나갈 수 없는 칸
                dist[ny][nx] = dist[cy][cx] + 1;
                
                if(board[ny][nx] != 0 && board[ny][nx] < sharkSize) {
                    fishv.push_back({dist[ny][nx], ny, nx});
                }
                q.push({ny, nx});
            }
        }
        
        if(fishv.empty()) break; // 먹을 물고기가 없다면 종료
        
        // 거리, 행, 열 순으로 정렬
        sort(fishv.begin(), fishv.end(), cmp);
        Fish target = fishv[0];
        
        totalTime += target.dist;
        sy = target.y;
        sx = target.x;
        board[sy][sx] = 0;  // 먹었으므로 해당 칸은 빈 칸
        
        eaten++;
        if(eaten == sharkSize) {
            sharkSize++;
            eaten = 0;
        }
    }
    
    cout << totalTime << "\n";
    return 0;
}
