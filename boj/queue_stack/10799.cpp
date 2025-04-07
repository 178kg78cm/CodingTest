#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main(){
    string input;
    cin >> input;

    stack<char> s;
    vector<int> num;
    int laser = 0;
    int count = 0;
    int bar = 0;
    for(int i=0;i<input.size();i++){
        char c = input[i];
        if(s.empty()){
            s.push(c);
            laser = 0;
            num.clear();
        }
        else{
            if(c==')'){
                if(s.top()=='('){ // 레이저
                    laser++;
                    bar--;
                }
                else{ // 쇠막대기 하나 끝
                    count += (num[num.size()-1] + 1);
                    bar--;
                    num.push_back(laser);
                    laser = 0;
                }
            }else{
                bar++;
            }

            s.push(c);
        }


    }
}
