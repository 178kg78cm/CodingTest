#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a, b;
    // -(1 2) -3 -(4 5 6) -(7 8) -9
    string s;
    cin >> s;
    int minus = 0;
    string num_str = "";
    int num = 0;
    int total = 0;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='+'){
            reverse(num_str.begin(),num_str.end());
            num += stoi(num_str);
            num_str = "";
        }else if(s[i]=='-'){
            reverse(num_str.begin(),num_str.end());
            num += stoi(num_str);
            num_str = "";
            total -= num;
            num = 0;
        }else{
            num_str.push_back(s[i]);
        }
    }
    
    if(num_str != "") {
        reverse(num_str.begin(),num_str.end());
        total += stoi(num_str);
    }if(num!=0){
        total += num;
    }

    cout << total;
    return 0;
}