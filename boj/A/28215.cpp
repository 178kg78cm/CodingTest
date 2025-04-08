#include <iostream>
#include <utility>
#include <vector>
using namespace std;


int main(){
    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> v(N);
    vector<vector<int>> dist(K, vector<int>(K,0));
    for(int i=0;i<N;i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    // N to N 거리재기
    for(int i=0;i<N;i++){ // 시작
        for(int j=0;j<N;j++){ // 끝
            if(i!=j){
                dist[i][j] = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
            }
        }
    }

    // K개를 골라
    

}