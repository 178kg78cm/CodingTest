#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct {
    int x;
    int y;
} Point;

bool cmp(Point a, Point b){
    if(a.x < b.x){
        return 1;
    }else if(a.x == b.x){
        if(a.y < b.y)
            return 1;
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    vector<Point> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr.begin(),arr.end(),cmp);

    for(int i=0;i<n;i++){
        cout << arr[i].x << ' ' << arr[i].y << '\n';
    }
    return 0;
}