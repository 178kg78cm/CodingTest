#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    queue<int> q;
    int arr[1001];
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    cin >> n;

    cout << '<';
    while(1){
        for(int i=0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        if(q.empty()) {
            cout << '>';
            break;
        }else{
            cout << ", ";
        }
    }
    return 0;
}