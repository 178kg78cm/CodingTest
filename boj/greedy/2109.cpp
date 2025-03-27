#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<int> req[MAX];

    for(int i=0;i<n;i++){
        int q, d;
        cin >> q >> d;
        req[d].push(q);
    }
    int answer=0;
    
    for(int i=n;i>0;i--){
        int max_d=0;
        int max_p=0;
        for(int j=i;j<MAX;j++){
            if(!req[j].empty()){
                if(max_p < req[j].top()){
                    max_d = j;
                    max_p = req[j].top();
                }
            }
        }
        answer += max_p;
        req[max_d].pop();
    }
    cout << answer;
    return 0;
}