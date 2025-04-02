#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    int from;
    int to;
} Move;
vector<Move> move;

int hanoi(int n){
    if(n==1){
        return 1;
    }
    
    hanoi(n-1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin >> K;
    
    return 0;
}