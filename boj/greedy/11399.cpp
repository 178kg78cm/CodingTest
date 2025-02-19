#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    sort(v.begin(),v.end());
    int sum = 0, tmp=0;
    for(int i=0;i<n;i++){
        sum +=  tmp + v[i];
        tmp += v[i];
    }
    cout << sum;
    return 0;
}
