#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> answer;
    string nums;
    while(n--){
        string s;
        cin >> s;
        bool zero=false;
        for(char c : s){
            if('0'<c && c <='9'){
                nums.push_back(c);
            } else if('0'==c){
                zero=true;
                if(!nums.empty()){ 
                   nums.push_back(c);
                    zero = false;   
                }
            }
            else{
                if(!nums.empty()){
                    answer.push_back(nums);
                    zero = false;   
                    nums.clear();
                } else if(zero) nums.push_back('0');
            }
        }
        if(!nums.empty()){
            answer.push_back(nums);
            nums.clear();
        } else if(zero) answer.push_back("0");
    }
    sort(answer.begin(),answer.end(),[](string a, string b){
        if (a.length() < b.length()) return 1;
        else if (a.length() == b.length()) {
            if(a < b) return 1;
            else return 0;
        }
        else return 0;
    });

    for(auto it=answer.begin();it!=answer.end();it++){
        cout << *it << '\n';
    }

    return 0;
}