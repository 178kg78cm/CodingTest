#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct {
    int v;// 가격
    int m;// 무게
} jem;
struct cmpValue{
    bool compare(jem a, jem b){
        if(a.v<b.v){
            return true;
        }else{
            return false;
        }
    }
};
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
    sort(jem_info.begin(),jem_info.end(),[](jem a, jem b){
        if(a.m>b.m) return true;
        else return false;
    });
    vector<bool> visited(N,0);
    priority_queue<jem,vector<jem>, cmpValue> q;

    for(int i=0;i<K;i++){
        for(int j=0;j<jem_info.size();j++){
            if(visited[j]==0){
                

            }
        }
        if()
        visited[j]=1;
    }

}