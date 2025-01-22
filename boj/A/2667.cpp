#include<bits/stdc++.h>
using namespace std;
int main(){
    int mmap[25][25];
    bool visited[25][25] = {0,};
    int n, cnt = 0;
    vector<int> bulid_num;
    set<pair<int,int>> pos;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<n;j++){
            mmap[i][j]=s[j]-'0';
            if(mmap[i][j]==1) {
                pos.insert({i,j});
            }
            else visited[i][j] = 1;
        }
    }
    int dx[4]={1,0,-1,0}, dy[4] = {0,1,0,-1};

    while(!pos.empty()){
        queue<pair<int,int>> q;
        q.push(*pos.begin());
        visited[pos.begin()->first][pos.begin()->second] = 1;
        pos.erase(pos.begin());
        int area=0;
        while(!q.empty()){
            int x,y;
            tie(y,x) = q.front();
            q.pop();
            area++;
            for(int i=0;i<4;i++){
                int nx = x+dx[i], ny=y+dy[i];
                if(nx<0||nx>=n||ny<0||ny>=n) continue;
                if(!visited[ny][nx]){
                    q.push({ny,nx});
                    visited[ny][nx]=1;
                    pos.erase({ny,nx});
                }
            }
        }
        bulid_num.push_back(area);
    }
    sort(bulid_num.begin(),bulid_num.end());
    cout << bulid_num.size() << '\n';
    for(auto it : bulid_num){
        cout << it << '\n';
    }
}