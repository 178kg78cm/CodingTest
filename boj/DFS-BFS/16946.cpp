#include <iostream>
#include <queue>
using namespace std;
int mmap[1001][1001];
int dx[4] = {1,0,-1,0}, dy[4] = {0, 1, 0, -1};
int main(){
    int n, m;
    cin >> n >> m;
    queue<pair<int,int>> wallq;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &mmap[i][j]);
            if(mmap[i][j]==1)
                wallq.push({i,j});
        }
    }
    

    while(!wallq.empty()){
        int by = wallq.front().first, bx=wallq.front().second;
        wallq.pop();
        queue<pair<int,int>> q;
        q.push({by,bx});

        bool visited[1001][1001] = {0,};
        mmap[by][bx] = 0;
        visited[by][bx] = 1;
        int y, x;
        int num = 1;
        while(!q.empty()){
            y=q.front().first;
            x=q.front().second;
            q.pop();
            int nx, ny;
            for(int i=0;i<4;i++){
                nx = x + dx[i];
                ny = y + dy[i];
                if(nx<0 || ny < 0 || nx >= m || ny >= n) continue;
                if(mmap[ny][nx]!= 0 || visited[ny][nx]==1) continue;
                visited[ny][nx] = 1;
                q.push({ny,nx});
                num++;
            }
        }
        mmap[by][bx] = (num % 10);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << mmap[i][j];
        }
        cout << '\n';
    }
}