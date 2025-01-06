#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int main(){
    int dx[4]={1,0,-1,0}, dy[4] = {0,1,0,-1};
    int n, m;
    cin >> n >> m;
    bool board[100][100] = {0,};
    int visitied[100][100] = {0,};
    cin.get();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            board[i][j] = cin.get() - '0';
        }
        cin.get();
    }
    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(ny<0||ny>=n||nx<0||nx>=m || !board[ny][nx]) continue;

            if(visitied[ny][nx]) continue;
            visitied[ny][nx] = visitied[y][x] + 1;
            q.push(make_pair(nx,ny));
        }
    }

    cout << visitied[n-1][m-1]+1;

    return 0;
}