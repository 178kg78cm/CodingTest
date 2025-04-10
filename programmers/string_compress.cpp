#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int compress(int n, string& s){
    int total_count = 0;
    int count = 1;
    int j;
    string substring = s.substr(0,n);
    string target;
    for(j=n;j<=s.size();j+=n){
        target = s.substr(j,n);
        if(substring == target){
            count++;
        }else{
            if(count>1){
                total_count += (to_string(count).size() + n);
            }
            else
                total_count += target.size();
            
            substring = target;
            count = 1;
        }
    }    
    // if(count>1){
    //     total_count += (to_string(count).size() + n);
    // }
    // else
    //     total_count += target.size();

    return total_count;
}
int solution(string s) {
    int answer = s.size();
    for(int i=1;i<=s.size()/2;i++){
        answer = min(answer, compress(i,s));
    }
    
    return answer;
}

int main(){
    string s;
    cin >> s;
    
    cout << solution(s);
    return 0;
}
