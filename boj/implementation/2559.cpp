#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> temp(n);
    vector<int> sum_temp;
    
    for(int i=0;i<n;i++){
        cin >> temp[i];
    }
    for(int i=0;i<n-k+1;i++){
        int sum = 0;
        for(int j=i;j<i+k;j++){
            sum+= temp[j];
        }
        sum_temp.push_back(sum);
    }

    cout << *max_element(sum_temp.begin(),sum_temp.end());
    return 0;
}