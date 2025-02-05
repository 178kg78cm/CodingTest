#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;

char maze[MAX][MAX];
int fire[MAX][MAX], jihun[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m;
queue<pair<int, int>> fire_q, jihun_q;

void bfs_fire() {
    while (!fire_q.empty()) {
        auto [x, y] = fire_q.front();
        fire_q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (maze[nx][ny] == '#' || fire[nx][ny] != -1) continue;

            fire[nx][ny] = fire[x][y] + 1;
            fire_q.push({nx, ny});
        }
    }
}

int bfs_jihun() {
    while (!jihun_q.empty()) {
        auto [x, y] = jihun_q.front();
        jihun_q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                return jihun[x][y] + 1;
            }

            if (maze[nx][ny] == '#' || jihun[nx][ny] != -1) continue;
            if (fire[nx][ny] != -1 && fire[nx][ny] <= jihun[x][y] + 1) continue;

            jihun[nx][ny] = jihun[x][y] + 1;
            jihun_q.push({nx, ny});
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    fill(&fire[0][0], &fire[0][0] + MAX * MAX, -1);
    fill(&jihun[0][0], &jihun[0][0] + MAX * MAX, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'F') {
                fire[i][j] = 0;
                fire_q.push({i, j});
            }
            if (maze[i][j] == 'J') {
                jihun[i][j] = 0;
                jihun_q.push({i, j});
            }
        }
    }

    bfs_fire();
    int result = bfs_jihun();
    
    if (result == -1) cout << "IMPOSSIBLE\n";
    else cout << result << "\n";
    
    return 0;
}
