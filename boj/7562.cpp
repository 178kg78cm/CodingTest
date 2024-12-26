#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>
using namespace std;
int dx[8] = {1,2,-1,-2,1,2,-1,-2};
int dy[8] = {2,1,2,1,-2,-1,-2,-1};

int bfs(int l, pair<int,int> start, pair<int,int> end){
    vector<vector<int>> visited(l, vector<int>(l,0));
    queue<pair<int,int>> q;
    
    visited[start.first][start.second];
    q.push(start);
    while(!q.empty()){
        auto x = q.front().first;
        auto y = q.front().second;

        q.pop();    
        if(x==end.first && y==end.second)
        {
            return visited[x][y];
        }
        for (int i = 0; i < 8; i++) {  // 8방향 이동
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < l && ny < l && !visited[nx][ny]) {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
        
    }

    return -1;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    while(n--){
        int l;
        cin >> l;
        pair<int,int> start, end;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;


        cout << bfs(l,start,end) << "\n";
    }

    return 0;
}