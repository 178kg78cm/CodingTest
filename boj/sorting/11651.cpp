#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct{
    int x;
    int y;
}Point;

bool cmp(Point a, Point b){
    if(a.y<b.y){
        return 1;
    }else if(a.y==b.y && a.x<b.x){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int n;
    cin >> n;
    vector<Point> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].x >> v[i].y;
    }
    
    sort(v.begin(), v.end(), cmp);
    for(int i=0;i<n;i++){
        cout << v[i].x << ' ' << v[i].y << '\n';
    }
    return 0;
}