#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    int start, end;
    for(int i = 0; i < n; i++){
        cin >> start >> end;
        v[i] = make_pair(start, end);
    }
    sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        if(a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });
    
    int count = 0;
    int fin = 0;
    for(auto & meeting : v){
        if(meeting.first >= fin){
            count++;
            fin = meeting.second;
        }
    }
    
    cout << count << "\n";
    return 0;
}
