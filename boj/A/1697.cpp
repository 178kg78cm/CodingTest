#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    queue<pair<int, int>> q;
    bool visited[100001] = {0,};
    q.push({n,0});
    while(!q.empty()){
        int pos, t;
        tie(pos,t) = q.front();
        if(pos==k){
            cout << t;
            break;
        }
        q.pop();

        int npos[3] = {pos+1, pos-1, pos*2};
        for(int i=0;i<3;i++){
            if((0 <= npos[i] && 100000 >= npos[i])){
                if(visited[npos[i]]==false){
                    visited[npos[i]]=true;
                    q.push({npos[i], t+1});
                }
            }
        }
    }

    return 0;
}