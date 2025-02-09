/*
첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 최대 100이다.

각 테스트 케이스의 첫째 줄에는 수행할 함수 p가 주어진다. p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.

다음 줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 ≤ n ≤ 100,000)

다음 줄에는 [x1,...,xn]과 같은 형태로 배열에 들어있는 정수가 주어진다. (1 ≤ xi ≤ 100)

전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string cmd, arr;
        int n;

        cin >> cmd;
        cin >> n;
        cin >> arr;
        
        deque<int> dq;
        string l;
        for(auto tmp : arr){
            if('0'<=tmp && tmp <= '9'){
                l.push_back(tmp);
            }
            else if(!l.empty()){
                dq.push_back(stoi(l));
                l.clear();
            }
        }

        bool direction = 1;
        bool error= 0;
        for(auto c : cmd){
            if(c == 'R'){
                direction = !direction;
            }else{
                if(!dq.empty()){
                    if(direction){  
                        dq.pop_front();
                    }else{
                        dq.pop_back();
                    }
                }else{
                    cout << "error\n";
                    error = 1;
                    break;
                }
            }
        }

        if(!error) {
            cout << '[';
            while(!dq.empty()){
                if(direction){
                    cout << dq.front();
                    dq.pop_front();
                }else{
                    cout << dq.back();
                    dq.pop_back();
                }
                if(dq.empty()){
                    break;
                }else{
                    cout << ',';
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}