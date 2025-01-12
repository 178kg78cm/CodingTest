#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int n5 = 0;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        n5 = 0;
        for(int i=5;i<=n;i=i*5)
            n5 += n/i;
        cout << n5 << '\n';
    }
    return 0;
}  