#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int len = 1;
        int onenum = 1;
        while(onenum%n != 0){
            onenum = onenum * 10 + 1;
            onenum %= n;
            len++;
        }
        cout << len << "\n";
    }

    return 0;
}