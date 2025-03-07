#include <iostream>
#include <queue>
using namespace std;

int n, m;
char mmap[1001][1001];
int visited[1001][1001][2]; 

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) cin >> mmap[i];

    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;

    while (!q.empty()) {
        auto [y, x, broken] = q.front(); q.pop();

        if (y == n - 1 && x == m - 1) {
            cout << visited[y][x][broken];
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            if (mmap[ny][nx] == '0' && !visited[ny][nx][broken]) {
                visited[ny][nx][broken] = visited[y][x][broken] + 1;
                q.push({ny, nx, broken});
            } else if (mmap[ny][nx] == '1' && broken == 0 && !visited[ny][nx][1]) {
                visited[ny][nx][1] = visited[y][x][broken] + 1;
                q.push({ny, nx, 1});
            }
        }
    }

    cout << -1;
}
