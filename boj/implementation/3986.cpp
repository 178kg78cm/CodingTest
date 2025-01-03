#include <iostream>
using namespace std;

int main(){
    int n, count = 0;
    cin >> n;getchar();
    while(n--){
        stack<char> s;
        char c;
        while((c=getchar())!='\n'){
            if(s.empty()){
                s.push(c);
            }else{
                if(s.top()==c) {
                    s.pop();
                }else{
                    s.push(c);
                }
            }
        }
        if(s.empty())
            count++;
    }
    cout << count;
    return 0;
}