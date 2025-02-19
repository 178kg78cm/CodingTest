#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> v(k);
    int pri, alc;
    for(int i=0;i<k;i++){
        cin >> pri >> alc;
        v[i] = make_pair(pri,alc);
    }
    int sum_pri = 0, sum_alc = 0;
    int level = 1;
    while(sum_pri > n && sum_alc < m)

    // 아무리해도 안되면 -1
    // sum(n) > m
}