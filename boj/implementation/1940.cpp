#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;

    cin >> n >> m;
    int ing, count=0;
    unordered_set<int> mset;
    for(int i=0;i<n;i++){
        cin >> ing;
        if(mset.find(m-ing)==mset.end()){
            mset.insert(ing);
        }else{
            count++;
        }
    }
    cout << count;

    return 0;
}