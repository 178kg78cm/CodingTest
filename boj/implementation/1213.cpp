#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){

    /*
    만약에 홀수가 두개이면 불가능.
    하나이면 가능.
    1. map에 넣는다?
    2. 배열에 넣는다?
    */
    map<char,int> pelin;
    char c; int valid = 0, len = -1;
    while((c=getchar())!='\n'){
        if(pelin.find(c)!=pelin.end()){
            pelin[c]++;
        }else{
            pelin.insert(make_pair(c,1));
        }
        len++;
    }
    char odd_key = 0;

    for(auto it = pelin.begin();it!=pelin.end();it++){
        if(it->second % 2) {
            valid++;
            odd_key = it->first;
        }
    }

    if(valid>1 || (len%2 && valid==1)) {
        cout << "I'm Sorry Hansoo";
    }
    else{
        vector<char> v(len+1);
        int n=0;
        for(auto it = pelin.begin();it!=pelin.end();it++){
            if(it->second % 2){
                it->second -= 1;
                v[len/2] = it->first;
            }
            while(it->second!=0){
                v[n] = it->first;
                v[len-n]=it->first;
                it->second -= 2;
                n++;
            }
        }
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it;
        }
    }
    
    return 0;
}