# C++ `sort` 함수의 시간 복잡도

C++ 표준 라이브러리에서 제공하는 `sort` 함수는 **시간 복잡도**가 **O(N log N)**입니다. 여기서 **N**은 정렬할 요소의 개수를 의미합니다.

## 정렬 알고리즘의 내부 작동 방식
C++의 `sort` 함수는 일반적으로 **Introsort**라는 알고리즘을 사용합니다. **Introsort**는 **퀵 정렬(Quick Sort)**, **힙 정렬(Heap Sort)**, 그리고 **삽입 정렬(Insertion Sort)**의 혼합 알고리즘입니다.

- **퀵 정렬**: 평균적으로 **O(N log N)**의 시간 복잡도를 가지지만, **최악의 경우**에는 **O(N^2)**의 시간 복잡도를 가질 수 있습니다.
- **Introsort**는 퀵 정렬을 기반으로 하지만, **최악의 경우**에는 **힙 정렬**로 전환하여 **O(N log N)**의 시간 복잡도를 보장합니다.
- **삽입 정렬**: 작은 데이터셋에 대해 최적화된 성능을 제공하며, `sort` 함수 내부에서 일부 구간에 적용될 수 있습니다.

## 요약
- **C++ `sort` 함수**의 평균 및 최악의 시간 복잡도는 **O(N log N)**입니다.