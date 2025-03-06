#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    // sort 1회에 case 3개 a, b / b, c / a, c
    vector<int>  v = {a, b, c};
    queue<vector<int>> q;
    set<vector<int>> s;
    int x,y;

    q.push(v);
    s.insert(v);
    while(!q.empty()){
        v = q.front();
        a=v[0];b=v[1];c=v[2];
        
        q.pop();

        if(v[0]!=v[1]){
            x = a + a;
            y = b - a;
            v = {x, y, c};
            if(x==y && y==c) {
                cout << 1;
                return 0;
            }
            sort(v.begin(),v.end());   
            auto result = s.insert(v);
            if(result.second){
                // a=v[0];b=v[1];c=v[2];
                // cout << a << ' ' << b << ' ' << c << endl;
                q.push(v);
            }
        }
        
        if(v[1]!=v[2]){
            x = b + b;
            y = c - b;
            v = {a, x, y};
            if(a==x && x==y) {
                cout << 1;
                return 0;
            }sort(v.begin(),v.end());   
            auto result = s.insert(v);
            if(result.second){
                // a=v[0];b=v[1];c=v[2];
                // cout << a << ' ' << b << ' ' << c << endl;
                q.push(v);
            }
        }
        if(v[0]!=v[2]){
            x = a + a;
            y = c - a;
            v = {x, b, y};
            if(x==b && b==y) {
                cout << 1;
                return 0;
            }sort(v.begin(),v.end());   
            auto result = s.insert(v);
            if(result.second){
                // a=v[0];b=v[1];c=v[2];
                // cout << a << ' ' << b << ' ' << c << endl;
                q.push(v);
            }
        }
    }
    cout << 0;
    return 0;
}