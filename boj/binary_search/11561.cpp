#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        unsigned long long N;
        cin >> N;

        unsigned long long l=1, r=N;
        unsigned long long result=1;
        if(N<3){
            cout << result << "\n";
            continue;
        }
        while(l<=r){
            unsigned long long n=(r+l)/2;
            unsigned long long step1=(n+1)*n/2;
            unsigned long long step2=(n+2)*(n+1)/2;
            if(step1<=N&&step2>N){
                cout << n << "\n";
                break;
            }else if(step1>N){
                r=n-1;
            }
            else{
                l=n+1;
            }
        }
    }

    return 0;
}