#include <iostream>
#include <queue>
using namespace std;
typedef struct{
    int y;
    int x;
} Point;
char board[101][101];
int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
int n;
bool visited[101][101];
bool visitedRG[101][101];

void bfs(int by, int bx, bool flag){
    queue<Point> q;
    q.push({by,bx});
    char color = board[by][bx];
    while(!q.empty()){
        Point p = q.front();
        int y= p.y, x=p.x;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || ny < 0 || ny >= n || nx >= n) 
                continue;

            if(flag){
                if(visitedRG[ny][nx]==0){
                    if(color == 'B'){
                        if(board[ny][nx] == 'B'){
                            visitedRG[ny][nx] = 1;
                            q.push({ny,nx});
                        }
                    }
                    else{
                        if(board[ny][nx] == 'G' || board[ny][nx]== 'R'){
                            visitedRG[ny][nx] = 1;
                            q.push({ny,nx});
                        }
                    }
                }
            }

            else{
                if(color == board[ny][nx] && visited[ny][nx] == 0){
                    visited[ny][nx] = 1;
                    q.push({ny,nx});
                }
            }

        }

    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> board[i];
    }

    int cnt = 0, cntRG = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0){
                bfs(i,j,0);
                cnt++;
            }
            if(visitedRG[i][j]==0){
                bfs(i,j,1);
                cntRG++;
            }
        }
    }

    cout << cnt << ' ' << cntRG;
    return 0;
}