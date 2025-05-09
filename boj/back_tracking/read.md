# 백트래킹(Backtracking)

백트래킹은 **결정 문제나 조합 최적화 문제**에서 **모든 가능한 경우를 탐색**하는 알고리즘 기법입니다. 단순히 모든 경우의 수를 무작정 탐색하는 것이 아니라, **불가능하거나 불필요한 경로는 미리 배제**하여 효율적으로 탐색을 줄이는 것이 핵심입니다.

## 백트래킹의 주요 개념

1. **상태 공간 탐색**:
   - 백트래킹은 모든 가능한 선택(상태)을 시도하는 **상태 공간 탐색** 기법입니다. 탐색할 공간이 매우 클 경우, 모든 경우를 탐색하는 대신, 올바른 해를 찾는 데 필요한 경로만 선택해 나갑니다.
   
2. **재귀적 탐색**:
   - 백트래킹은 **재귀 함수**를 사용하여 모든 경우를 시도해봅니다. 각 선택을 시도하면서 가능한 경우의 수를 줄여 나가고, 더 이상 해를 찾을 수 없는 경로는 **되돌아가서(Backtrack)** 다른 경로를 탐색합니다.

3. **가지치기(Pruning)**:
   - 탐색 도중 **유망하지 않은 경로**가 있을 경우, 더 이상 탐색하지 않고 **해당 경로를 포기**하고 다음 경로로 넘어갑니다. 이를 가지치기라고 부릅니다.
   - 예를 들어, N-Queen 문제에서는 같은 행, 열, 또는 대각선에 퀸이 있다면 더 이상 그 경로는 유망하지 않으므로 탐색을 종료하고 이전 상태로 되돌아갑니다.

## 백트래킹의 동작 방식

1. **문제 정의**: 
   - 해결하려는 문제를 **재귀적으로** 해결할 수 있도록 정의합니다. 각 단계에서 여러 선택지가 존재하며, 그 중 하나를 선택하고 그 선택에 맞춰 문제를 해결합니다.
   
2. **탐색 시작**:
   - 첫 번째 선택을 하고, 그 선택이 올바른지 확인합니다. 이후 선택이 가능하다면 **다음 선택으로 넘어가고**, 그렇지 않다면 **해당 선택을 포기**하고 **이전 상태로 되돌아갑니다**.
   
3. **해를 찾는 과정**:
   - 백트래킹은 해가 나올 때까지 모든 가능성을 시도합니다. 해를 찾았을 때는 결과를 저장하고, 더 많은 해를 찾을 수 있는지 탐색을 계속합니다.
   
4. **탐색 종료**:
   - 모든 선택을 시도했거나 해를 찾은 경우, 더 이상 선택지가 없으면 탐색을 종료합니다.

## 백트래킹의 예시: N-Queen 문제

N-Queen 문제는 백트래킹의 대표적인 예시입니다. N x N 체스판에 N개의 퀸을 서로 공격하지 않도록 배치하는 문제로, 백트래킹을 사용하여 퀸을 한 행씩 배치해 나가면서 올바른 배치를 찾습니다.

### N-Queen 문제의 백트래킹 과정

1. **첫 번째 퀸**을 첫 번째 행에 배치합니다.
2. **두 번째 퀸**을 두 번째 행에 놓으려고 할 때, 첫 번째 퀸과 같은 열 또는 대각선에 놓일 수 없습니다. 그렇다면 다른 위치에 배치합니다.
3. **세 번째 퀸**도 마찬가지로, 앞서 배치된 두 퀸과 겹치지 않도록 배치합니다.
4. 만약 특정 행에 퀸을 놓을 수 없으면, 다시 이전 행으로 돌아가서 퀸의 위치를 변경합니다(**Backtrack**).
5. 모든 퀸을 올바르게 배치할 수 있을 때까지 이 과정을 반복합니다.

```cpp
#include <iostream>
using namespace std;

int N, result = 0;
bool col[15], diagL[30], diagR[30];  // 열, 좌하향 대각선, 우하향 대각선 체크

void queen(int row) {
    if (row == N) {  // 모든 퀸을 배치한 경우
        result++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!col[i] && !diagL[row - i + N - 1] && !diagR[row + i]) {  // 가지치기
            col[i] = diagL[row - i + N - 1] = diagR[row + i] = true;  // 퀸 배치
            queen(row + 1);  // 다음 행으로 넘어감
            col[i] = diagL[row - i + N - 1] = diagR[row + i] = false;  // 백트래킹 (상태 복구)
        }
    }
}

int main() {
    cin >> N;
    queen(0);
    cout << result;
}
