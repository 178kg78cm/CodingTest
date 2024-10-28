#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num;
    queue<int> q;
    cin >> n;
    string s;
    while(n--){
        cin >> s;
        if(s=="empty"){
            if(q.empty())
                cout << "1\n";
            else
                cout<< "0\n";
        }
        else if(s=="push"){
                cin >> num;
                q.push(num);
        }
        else if(s=="size")
             cout << q.size() << "\n";
        else if(q.empty())
            cout<< "-1\n";
        else{
            if(s=="front")
                cout << q.front()  << "\n";
            else if(s=="back")
                cout << q.back()  << "\n";
            else if(s=="pop"){
                cout << q.front()  << "\n";
                q.pop();
            }
        }
    }
    return 0;
}
