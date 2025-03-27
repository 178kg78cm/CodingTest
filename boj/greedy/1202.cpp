#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct {
    int v;// 가격
    int m;// 무게
} jem;
bool cmpWeight(jem a, jem b){
    if(a.m>b.m){
        return true;
    }else{
        return false;
    }
}
int main(){
    int N, K;
    cin >> N >> K;
    vector<jem> jem_info;
    vector<int> back_info;
    int m, v;
    for(int i=0;i<N;i++){
        cin >> m >> v;
        jem_info.push_back({m,v});
    }
    for(int i=0;i<K;i++){
        cin >> m;
        back_info.push_back(m);
    }
    int answer = 0;
    sort(back_info.begin(),back_info.end(),greater());
    sort(jem_info.begin(),jem_info.end(),cmpWeight);
    priority_queue<jem> q;
    for(int i=K;i>=0;i--){
        for(int j=0;)
        if(jem_info[i].m <= back_info[i]){
            q.push(jem_info[i]);
        }
    }

}