#include <iostream>
#include <string>
using namespace std;

int tree[64][64];

void abstract(int n, int y, int x) {
    int base = tree[y][x];
    bool same = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tree[y + i][x + j] != base) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    // 압축 가능하면 base 값을 출력
    if (same) {
        cout << base;
        return;
    }

    // 압축 불가능하면 사분면으로 나누고 재귀 호출
    cout << '(';
    int half = n / 2;
    abstract(half, y, x);
    abstract(half, y, x + half);
    abstract(half, y + half, x);
    abstract(half, y + half, x + half);
    cout << ')';
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            tree[i][j] = s[j] - '0';
        }
    }

    if(N==1){
        cout << tree[0][0];
    }else if(N==2){
        if(tree[0][0]==tree[0][1]) cout << tree[0][0];
        else cout << '(' << tree[0][0] << tree[0][1] << ')';
    }else{
        abstract(N, 0, 0); 
    }
    return 0;
}
