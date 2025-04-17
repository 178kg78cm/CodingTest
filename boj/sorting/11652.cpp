#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<ll> v(n+1);
    
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    v[n] = (1 << 31);
    long long k = 1 << 30;
    cout << k << ' ';
    sort(v.begin(),v.end());
    int cnt = 1;
    int max_cnt = 0;
    int answer = 0;
    for(int i=0;i<=n;i++){
        if(v[i]==v[i-1]){
            cnt++;
        }else{
            if(max_cnt < cnt){
                answer = v[i-1];
                max_cnt = cnt;
            }
            cnt = 1;
        }
    }

    cout << answer;
    return 0;
}
// 1 1 1 2 2 3 5 5