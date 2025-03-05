#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    
    for (int i = 0; i < n; i++){
        int arrival, duration;
        cin >> arrival >> duration;
        v[i] = {arrival, duration};
    }
    
    sort(v.begin(), v.end());
    
    long long current_time = 0;
    for (auto &cow : v) {
        current_time = max(current_time, cow.first) + cow.second;
    }
    
    cout << current_time << "\n";
    return 0;
}
