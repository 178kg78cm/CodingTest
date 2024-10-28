#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;

    int n, cmd;
    cin >> n;
    while(n--){
        cin >> cmd;
        if(cmd == 1){
            cin >> cmd;
            s.push(cmd);
        }
        else if(s.empty() && cmd!=3){
            if(cmd == 4){
                cout << "1\n";
            } else{
                cout << "-1\n";
            }
        }
        else{
            if(cmd==3){
                cout << s.size() << "\n";
            } else if(cmd == 2){
                cout << s.top() << "\n";
                s.pop();
            } else if(cmd == 5){
                cout << s.top() << "\n";
            } else cout << "0\n";
        }
    }
    return 0;
}