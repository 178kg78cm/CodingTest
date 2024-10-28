#include <iostream>
using namespace std;
int main(){
    long long int n;
    cin >> n;
    cout << n*n << "\n" << 2 << "\n" ;
    return 0;
}

// 이 문제에서는 입력의 크기를 확인하는 것이 중요하다.
// 문제 : 첫째 줄에 입력의 크기 n(1 ≤ n ≤ 500,000)이 주어진다.
// 여기서 최대 500,000*500,000연산이 필요하다. 즉 천억이 넘는 값을 출력해야하므로 int, unsigned int가 아닌 long long형을 필요로한다.