#include <iostream>
#include <deque>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    deque<int> deq;
    int n, cmd;

    cin >> n;

    while(n--){
        cin >> cmd;
        if(cmd==1){
            cin >> cmd;
            deq.push_front(cmd);
        } else if(cmd==2){
            cin >> cmd;
            deq.push_back(cmd);
        } else if(deq.empty()){
            if(cmd==6){
                cout << "1\n";
            } else if(cmd==5){
                cout << "0\n";
            } else{
                cout << "-1\n";
            }
        } else{
            if(cmd==3){
                cout << deq.front() << "\n";
                deq.pop_front();
            } else if(cmd==4){
                cout << deq.back() << "\n";
                deq.pop_back();
            } else if(cmd==5){
                cout << deq.size() << "\n";
            } else if(cmd==6){
                cout << "0\n";
            } else if(cmd==7){
                cout << deq.front() << "\n";
            } else{
                cout << deq.back() << "\n";
            }
        }
    }
}