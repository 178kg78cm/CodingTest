#include <iostream>
#include <cmath> 
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long x, y;

    cin >> x >> y;

    int z=(y*100)/x; // 승률 z
    long long l=0,r=1000000000, m;

    int max_iter = static_cast<int>(log2(r)) + 1;
    long long result = -1;

    while(l<=r && max_iter--){
        m=(r+l)/2;
        if(z<(y+m)*100/(x+m)){
            r=m-1;
            result = m;
        }else{ 
            l=m+1;
        }
    }

    cout << result;

    return 0;
}