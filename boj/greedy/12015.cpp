#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> v;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    if(N==1){
        cout << 1;
        return 0;
    }

    stack<int> s;
    s.push(v[N-1]);
    for(int i=N-2;i>=0;i--){
        if(s.top()<=v[i]){
            s.pop();
        }
        s.push(v[i]);
    }
    cout << s.size();
    return 0;
}