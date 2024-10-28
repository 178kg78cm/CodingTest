#include<iostream>
using namespace std;

int arr[9][9];
int zero_cnt = 0;

bool check(int k, int row, int col) {
    for (int i = 0; i < 9; i++) {
        if (k == arr[row][i]) return false;  // 행 체크
    }
    for (int i = 0; i < 9; i++) {
        if (k == arr[i][col]) return false;  // 열 체크
    }
    for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++) {
        for (int j = col / 3 * 3; j < col / 3 * 3 + 3; j++) {
            if (k == arr[i][j]) return false;  // 3x3 박스 체크
        }
    }
    return true;
}

bool sudo(int n, int i, int j) {
    if (n == 0) {
        // 스도쿠 퍼즐 출력
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        return true;
    }

    // 빈 칸 찾기
    for (; i < 9; i++) {
        for (; j < 9; j++) {
            if (arr[i][j] == 0) {
                for (int k = 1; k <= 9; k++) {
                    if (check(k, i, j)) {
                        arr[i][j] = k;
                        if (j == 8) {  // 마지막 열이라면 다음 행으로
                            if (sudo(n - 1, i + 1, 0)) return true;
                        } else {  // 같은 행의 다음 열로
                            if (sudo(n - 1, i, j + 1)) return true;
                        }
                        arr[i][j] = 0;  // 백트래킹
                    }
                }
                return false;  // 가능한 값이 없을 때
            }
        }
        j = 0;  // 새 행으로 넘어가면 열 초기화
    }
    return false;
}

int main() {
    int n;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> n;
            arr[i][j] = n;
            if (n == 0) zero_cnt++;
        }
    }
    sudo(zero_cnt, 0, 0);
    return 0;
}


#include <iostream>
using namespace std;

int board[9][9];
int zeros, zerocnt;

bool propercheck(int x, int y, int k) {
    int xx = (x / 3) * 3, yy = (y / 3) * 3;

    // 가로, 세로 확인
    for (int i = 0; i < 9; i++) {
        if (board[i][y] == k || board[x][i] == k) return false;
    }

    // 3x3 박스 확인
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[xx + i][yy + j] == k) return false;
        }
    }

    return true;
}

bool sudoku(int n) {
    if (zerocnt == zeros) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) cout << board[i][j] << ' ';
            cout << endl;
        }
        return true;
    }

    int i = n / 9, j = n % 9;

    if (board[i][j] == 0) {	
        for (int k = 1; k <= 9; k++) {
            if (propercheck(i, j, k)) {
                board[i][j] = k; zerocnt++;
                if (sudoku(n + 1)) return true;
                board[i][j] = 0; zerocnt--;
            }
        }
    } else {
        return sudoku(n + 1);
    }

    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) zeros++;
        }
    }
    sudoku(0);

    return 0;
}


#include<iostream>
using namespace std;

int arr[9][9];
bool rowCheck[9][10], colCheck[9][10], boxCheck[9][10];
int zero_cnt = 0;

int getBoxIndex(int row, int col) {
    return (row / 3) * 3 + col / 3;  // 박스 인덱스를 구하는 함수
}

bool sudo(int n) {
    if (n == 0) {
        // 퍼즐 완성 시 출력
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        return true;
    }

    // 빈 칸 찾기
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] == 0) {
                int boxIndex = getBoxIndex(i, j);  // 박스 인덱스 계산

                for (int k = 1; k <= 9; k++) {
                    if (!rowCheck[i][k] && !colCheck[j][k] && !boxCheck[boxIndex][k]) {
                        arr[i][j] = k;
                        rowCheck[i][k] = colCheck[j][k] = boxCheck[boxIndex][k] = true;  // 체크 업데이트

                        if (sudo(n - 1)) return true;

                        arr[i][j] = 0;  // 백트래킹
                        rowCheck[i][k] = colCheck[j][k] = boxCheck[boxIndex][k] = false;  // 체크 해제
                    }
                }
                return false;  // 가능한 값을 못 찾으면 되돌아가기
            }
        }
    }
    return false;
}

int main() {
    int n;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> n;
            arr[i][j] = n;
            if (n == 0) zero_cnt++;
            else {
                int boxIndex = getBoxIndex(i, j);
                rowCheck[i][n] = true;
                colCheck[j][n] = true;
                boxCheck[boxIndex][n] = true;
            }
        }
    }
    sudo(zero_cnt);
    return 0;
}