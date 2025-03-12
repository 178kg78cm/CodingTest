#include <stdio.h>

typedef struct {
    int x, y, k;
} Point;

#define QSIZE 1000000  // 큐의 크기 (적절하게 조정)

int board[1001][1001];
int visited[1001][1001][11];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
Point q[QSIZE];

int main(void) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &board[i][j]);  // 개행 자동 처리
        }
    }

    int front = 0, end = 0;  // 원형 큐이므로 초기화 값 조정
    q[end] = (Point){0, 0, 0}; // 시작점 삽입
    visited[0][0][0] = 1;
    end = (end + 1) % QSIZE; // end 증가 (원형 큐)

    while (front != end) {
        Point cur = q[front];
        front = (front + 1) % QSIZE; // front 증가 (원형 큐)

        if (cur.y == n - 1 && cur.x == m - 1) {
            printf("%d\n", visited[cur.y][cur.x][cur.k]);
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int ndepth = cur.k;

            if (ny >= n || nx >= m || ny < 0 || nx < 0) continue;
            if (board[ny][nx]) {
                if (cur.k + 1 > k) continue;
                ndepth++;
            }
            if (visited[ny][nx][ndepth]) continue;

            visited[ny][nx][ndepth] = visited[cur.y][cur.x][cur.k] + 1;
            q[end] = (Point){nx, ny, ndepth};
            end = (end + 1) % QSIZE; // end 증가 (원형 큐)
        }
    }

    printf("-1\n");
    return 0;
}
