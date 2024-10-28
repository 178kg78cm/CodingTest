# C++ 팁

## 빠른 출력
1. cin.tie(NULL);
cin과 cout의 입출력 묶음을 풀어서 속도 향상
구체적으로 말하면 cin으로 입력이 들어오면 출력 버퍼에 내용이 있는 경우 버퍼를 비워(flush) 출력한다. 따라서, 입출력이 반복되는 경우 매번 일일이 버퍼를 비우느라 시간이 더 걸린다.

2. ios::sync_with_stdio(false);
는 C의 stdio와 C++의 iostream의 동기화를 비활성화 한다.
즉 scanf, gets, getchar 호환 제한.

3. '\n'이 버퍼를 비워주지 않으므로 endl보다 빠르다. 

- 백준 15552번


## #include <bits/stdc++.h>


# circler queue 개념 정리

# pair

# vector