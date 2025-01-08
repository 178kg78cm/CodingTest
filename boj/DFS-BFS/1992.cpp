#include<bits/stdc++.h>
using namespace std;
string board[64];
bool visitied[100][100] = { 0, };
vector<int> sqr2;
string tree;
// 하나는 무조건 모든 영역을 검사하는 함수
bool search(int y, int x, int range, int t);
void dq(int y, int x, int t);

int main(){
    int N;
    cin >> N;
    int n = N;

    while(n%2==0) {sqr2.push_back(n);n=n/2;}
    sqr2.push_back(1);
    // 영역 가르기

    for(int i=0;i<N;i++){
        cin >> board[i];
    }
    dq(0,0,0);

    return 0;
}

bool search(int y, int x, int range, int t){
    bool base = board[y][x];
    
    for(int i=y;i<y+range;i++){
        for(int j=x;j<x+range;j++){
            if(base!=board[i][j]){ // 다른 포지션 찾았을 때
                tree.push_back('(');
                dq(i/range*range,j/range*range,t+1);
                tree.push_back(')');
                return false;
            }
        }
    }
    return true;
}
void dq(int y, int x, int t){
    int range = sqr2[t+1];
    int dx[4] = {0,range,0,range}, dy[4] = {0,0,range,range};
    bool base = board[y][x];
    int check = -1;
    for(int k=0;k<4;k++){
        int nx = x+dx[k], ny = y+dy[k];
        if(search(ny,nx, range, t))
            check = base;
    }
    if(check==base) tree.push_back(base);
    if(range==1) return;
}
