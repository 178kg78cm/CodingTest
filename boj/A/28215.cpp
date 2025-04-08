#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

vector<vector<int>> combination;
vector<int> current;
void combi_generate(int start){
    if(current.size()==K){
        combination.push_back(current);
        return;
    }
    for(int i=start;i<N;i++){
        current.push_back(i);
        combi_generate(i+1);
        current.pop_back();
    }

}
int main(){
    cin >> N >> K;
    vector<pair<int,int>> v(N);
    vector<vector<int>> dist(N, vector<int>(N,0));
    for(int i=0;i<N;i++){
        int x, y;
        cin >> x >> y;
        v[i] = {x,y};
    }
    // N to N 거리재기
    for(int i=0;i<N;i++){ // 시작
        for(int j=0;j<N;j++){ // 끝
            if(i!=j){
                dist[i][j] = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
            }
        }
    }
    combi_generate(0);
    // K개를 골라
    int num_of_combi = combination.size();
    vector<int> min_dist;
    for(int j=0;j<num_of_combi;j++){
        vector<int> max_dist;
        for(int k=0;k<N;k++){
            int min = 1e9;
            for(int i=0;i<K;i++){
                int curr = dist[combination[j][i]][k];
                if(curr<min) min = curr;
            }
            max_dist.push_back(min);
        }
        min_dist.push_back(*max_element(max_dist.begin(),max_dist.end()));
    }

    if(min_dist.size()==0) cout << 0;
    else{
        cout << *min_element(min_dist.begin(),min_dist.end()); 

    }

    return 0;
}