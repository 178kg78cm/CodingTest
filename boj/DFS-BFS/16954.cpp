#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int y, x;
};

char mmap[8][8];
queue<Point> wallq;
queue<Point> q;

int dx[9] = {1, 0, -1, 0, 1, -1, 1, -1, 0}; 
int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력: 8x8 보드
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '#') {
                wallq.push({i, j});
            }
        }
    }

    q.push({7, 0});

    while (!q.empty()) {
        // 매 시간 단계마다 방문 배열을 새로 생성
        bool visited[8][8] = {0};
        int q_size = q.size();
        while (q_size--) {
            Point man = q.front();
            q.pop();

            if (mmap[man.y][man.x] == '#') continue;  // 현재 위치가 벽이면 무시

            if (man.y == 0 && man.x == 7) {
                cout << 1;
                return 0;
            }

            for (int i = 0; i < 9; i++) {
                int nx = man.x + dx[i], ny = man.y + dy[i];
                if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8)
                    continue;
                if (!visited[ny][nx] && mmap[ny][nx] == '.') {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }

        int wall_s = wallq.size();
        queue<Point> newWallq;
        while (wall_s--) {
            Point p = wallq.front();
            wallq.pop();
            mmap[p.y][p.x] = '.';  // 기존 벽 제거

            if (p.y < 7) {  // 벽이 아래로 이동할 수 있으면
                mmap[p.y + 1][p.x] = '#';
                newWallq.push({p.y + 1, p.x});
            }
        }
        wallq = newWallq;
    }

    cout << 0;
    return 0;
}
