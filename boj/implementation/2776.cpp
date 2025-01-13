#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    int n, m;
    cin >> t;
    while(t--){
        set<int> mset;
        cin >> n;
        int k;
        for(int i=0;i<n;i++){
            cin >> k;
            mset.insert(k);
        }
        cin >> m;
        for(int i=0;i<m;i++){
            int num;
            cin >> num;
            if(mset.find(num)!=mset.end()){
                cout << 1  << '\n';
            }else cout << 0 << '\n';
        }
    }
    return 0;
}