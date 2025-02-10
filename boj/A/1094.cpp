#include <iostream>
// 비트마스킹으로도 풀 수 있는 문제이나 그렇게 하지 않음
/*
#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;  // 목표 길이 입력 받기

    // 목표 길이를 2진수로 표현했을 때 1의 개수를 셈
    int result = 0;
    while (x > 0) {
        if (x % 2 == 1)  // 1인 자리를 찾으면
            result++;     // 자른 막대기의 개수를 하나 증가시킴
        x /= 2;  // x를 반으로 나누기
    }

    cout << result << endl;  // 필요한 막대기의 개수 출력
    return 0;
}
*/
using namespace std;
int main(){
    int l = 64;

    int x;
    cin >> x;
    int time = 1, min = 64;
    while(l!= x){
        min = min/2;
        if(l-min >= x) {
            l-=min;
            time--;
        }
        time++;
    }
    cout << time;
}

// 0. 64
// 1. 32, 32(버림)
// 2. 16, 16
// 3. 16 8 8(버림)
// 4. 16 4 4
// 5. 16 4 2 2
// 6. 16 4 2 1 1(버림)
// 16 4 2 1