#include <bits/stdc++.h>
/* 숫자를 세는 부분에서 전체적으로 코드가 지저분함.
벡터 삽입부터 영역 세는 부분을 다시 체크하자*/

using namespace std;
bool board[100][100] = {0,};
bool visitied[100][100] = { 0, };
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int m, n, k, area= 0;
vector<int> areas;

int dfs(int y, int x){
    visitied[y][x] = true;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0||ny>=m||nx<0||nx>=n) continue;
        if(!visitied[ny][nx]&&!board[ny][nx]) {
            dfs(ny,nx);
            area++;
        }
    }
    return area;
}
int main(){

    cin >> m >> n >> k;
    int count = 0;

    while(k--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=y1;i<y2;i++){
            for(int j = x1; j < x2; j++){
                board[i][j] = 1;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visitied[i][j]&&!board[i][j]){
                count++;
                area = 0;
                areas.push_back(dfs(i,j)+1);
            }
        }
    }
    cout << count << '\n';
    sort(areas.begin(),areas.end());
    for(auto v=areas.begin();v!=areas.end();v++)
        cout << *v << ' ';

    return 0;
}