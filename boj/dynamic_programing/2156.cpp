#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> wine(n);

    for(int i=0;i<n;i++)
        cin >> wine[i];

    vector<int> dp(n,0);

    if(n==1){
        cout << wine[0];
        return 0;
    }if(n==2){
        cout << wine[0]+wine[1];
        return 0;
    }

    dp[0]=wine[0];
    dp[1]=wine[0]+wine[1];
    dp[2]=max(dp[1],max(wine[2]+wine[0],wine[2]+wine[1]));
    for(int i=3;i<n;i++){
        dp[i] = max(dp[i-2]+wine[i],max(dp[i-1],dp[i-3]+wine[i]+wine[i-1]));
    }
    cout << dp[n-1];
    return 0;
}