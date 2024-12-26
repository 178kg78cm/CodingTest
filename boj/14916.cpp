#include <iostream>

using namespace std;

int main(){
    int n;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;

    int five = n/5;
    while(1){
        int two = (n-five*5)/2;
        if((n-five*5)%2 == 1){
            if(five==0) {
                cout << "-1\n";
                break;
            }

            five--;
        }
        else{
            cout << five+two;
            break;
        }
    }
    return 0;
}