#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> v;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    if(N==1){
        cout << 1;
        return 0;
    }

    
    return 0;
}