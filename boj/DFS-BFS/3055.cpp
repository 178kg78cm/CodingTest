#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef struct {
    int y; 
    int x;
 } Point;
 
char board[51][51];
int dvisited[51][51];
bool wvisited[51][51];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int main(){
    int r, c;
    cin >> r >> c;
    cin.get();
    Point d, s;
    queue<Point> dq, wq;
    vector<int> wq_numlist;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            board[i][j] = cin.get();
            if(board[i][j] == 'S'){
                d = (Point){i,j};
                dq.push(d);
            }else if(board[i][j] == 'D'){
                s = (Point){i,j};
            }else if(board[i][j] == '*'){
                wq.push((Point){i,j});
                wq_numlist.push_back(1);
                wvisited[i][j] = 1;
            }
        }
        cin.get();
    }
    dvisited[d.y][d.x] = 1;
    while(!dq.empty()){
        
        for(int i=0;i<wq_numlist.size();i++){
            int num = 0;
            for(int j=0;j<wq_numlist[i];j++){
                // 물 먼저 탐색하고 진행. " 즉, 다음 시간에 물이 찰 예정인 칸으로 고슴도치는 이동할 수 없다. "
                int w_x = wq.front().x, w_y = wq.front().y;
                wq.pop();

                int ny, nx;
                for(int k=0;k<4;k++){
                    ny = w_y + dy[k];
                    nx = w_x + dx[k];
        
                    if(nx < 0 || ny < 0 || nx >= c || ny >= r){
                        continue;
                    }
                    if(board[ny][nx] == 'X' || wvisited[ny][nx] == true || board[ny][nx]=='D') continue;
                    wvisited[ny][nx]= true;
                    wq.push((Point){ny,nx});
                    // cout << ny << '=' << nx << endl;
                    num++;
                }
            }
            wq_numlist[i] = num;
        }
        int q_size = dq.size();
        while(q_size--){
            int d_x = dq.front().x, d_y = dq.front().y;
            dq.pop();
            for(int i=0;i<4;i++){ // 비버 탐색 물 
                int ny, nx;
                ny = d_y + dy[i];
                nx = d_x + dx[i];
    
                if(nx < 0 || ny < 0 || nx >= c || ny >= r){
                    continue;
                }
                if(board[ny][nx] == 'X' || wvisited[ny][nx] == true || dvisited[ny][nx] > 0 ) continue;
                
                dvisited[ny][nx] = dvisited[d_y][d_x] + 1;
                if(nx == s.x && ny == s.y){
                    cout << dvisited[ny][nx]-1;
                    return 0;
                }
                dq.push((Point){ny,nx});
                // cout << ny << '-' << nx << ' '<< dvisited[ny][nx] -1<< endl;
            }
        }
    }

    cout << "KAKTUS";
    return 0;
}