#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> v1(N+M);
    for(int i=0;i<N+M;i++){
        cin >> v1[i];
    }
    sort(v1.begin(),v1.end());
    v1.erase(unique(v1.begin(),v1.end()),v1.end());

    for(int i=0;i<v1.size();i++){
        cout << v1[i] << ' ';
    }
    return 0;
}