#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    vector<int> freq(100001, 0); // 빈도 기록
    
    long long ans = 0;
    int left = 0;
    for (int right = 0; right < n; right++){
        freq[v[right]]++;
        while(freq[v[right]] > 1){
            freq[v[left]]--;
            left++;
        }
        ans += (right - left + 1);
    }
    
    cout << ans << "\n";
    return 0;
}
