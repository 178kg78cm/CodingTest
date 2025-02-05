#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int mmap[100001] = {0,};
int n, k;
int min_dist  = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill(&mmap[0],&mmap[100001],-1);
    queue<pair<int, int>> q;
    q.push({k,1});

    while(!q.empty()){
        auto [pos, t] = q.front();
        q.pop();
        int next_list[3] = {pos-1, pos+1, pos/2};
        if(pos%2) next_list[2] = -1;
        if(pos == n) {
            cout << t-1 << '\n';
            break;
        }
        for(int i=0;i<3;i++){
            int next_pos = next_list[i];
            if(next_pos < 0 || next_pos>100000 || next_pos == -1) continue;
            if(mmap[next_pos]!=-1) continue;
            q.push({next_pos,t+1});
            mmap[next_pos] = pos;
        }
    }
    for(int i=n;i!=k;i=mmap[i]){
        cout << i << ' ';
    } cout << k;

    return 0;
}