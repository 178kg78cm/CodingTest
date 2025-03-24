#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> coins;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        coins.push_back(tmp);
    }
    
    int cnt = 0;
    for (int i = n-1; i >= 0; i--){
        if (k == 0) break;
        if (coins[i] <= k) {
            cnt += k / coins[i];
            k %= coins[i];
        }
    }
    
    cout << cnt << '\n';
    return 0;
}
