#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct{
    string name;
    int k;
    int e;
    int m;
} Score;
bool cmp(Score a, Score b){
    if(a.k == b.k) {
        if(a.e == b.e){
            if(a.m == b.m){
                return a.name < b.name;
            }
            return a.m > b.m;
        }
        return a.e < b.e;
    } 
    return a.k > b.k;
}
int main(){
    int n;
    cin >> n;
    vector<Score> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i].name >> v[i].k >> v[i].e >> v[i].m;
    }

    sort(v.begin(),v.end(), cmp);

    for(int i=0;i<n;i++){
        cout << v[i].name << '\n';
    }
    return 0;
}