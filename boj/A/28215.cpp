#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> v(N);

    for(int i=0;i<N;i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x,y});
    }
}