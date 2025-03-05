#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    // sort 1회에 case 3개 a, b / b, c / a, c
    int group[3] = {a, b, c};
    sort(group,group+3);
    if(group[0]!=group[1]){

    }
    if(group[1]!=group[2]){
        
    }
    if(group[0]!=group[2]){
        
    }
}