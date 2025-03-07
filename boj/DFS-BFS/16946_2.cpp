#include <iostream>
#include <queue>
#include <map>
using namespace std;
int mmap[1001][1001];
int dx[4] = {1,0,-1,0}, dy[4] = {0, 1, 0, -1};
int main(){
    int n, m;
    cin >> n >> m;
    queue<pair<int,int>> wallq, roadq;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &mmap[i][j]);
            if(mmap[i][j]==1){
                mmap[i][j] = -1;
            }
            else{
                roadq.push({i,j});
            }
        }
    }

    map<int,int> mgroup;
    int group = 1;
    while(!roadq.empty()){
        int by = roadq.front().first, bx=roadq.front().second;
        roadq.pop();
        if(mmap[by][bx]!=0){
            continue;
        }

        queue<pair<int,int>> q;
        q.push({by,bx});
        mmap[by][bx] = group;

        int num = 0;
        int y, x;
        while(!q.empty()){
            y=q.front().first;
            x=q.front().second;
            q.pop();
            int nx, ny;
            for(int i=0;i<4;i++){
                nx = x + dx[i];
                ny = y + dy[i];
                if(nx<0 || ny < 0 || nx >= m || ny >= n) continue;
                if(mmap[ny][nx]!= 0) continue;
                mmap[ny][nx] = group;
                q.push({ny,nx});
                num++;
            }
        }
        mgroup.insert({group,num});
        group++;
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int nx,ny, size = 1;
            if(mmap[i][j]==-1){
                for(int i=0;i<4;i++){
                    nx = i + dx[i];
                    ny = j + dy[i];
                    
                    if(nx<0 || ny < 0 || nx >= m || ny >= n) continue;
                    if(mmap[ny][nx]==-1) continue;
                    size += mgroup[mmap[ny][nx]];
                }
                cout << size % 10;
            }
            else cout << 0;
        }
        cout << '\n';
    }
}