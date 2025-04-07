#include <bits/stdc++.h>
using namespace std;

const int MX = 3;
int dat[MX];
int head = 0, tail = 0;

void push(int x){
  dat[tail]=x;
  tail = (tail+1) % MX;
}

void pop(){
  head = (head + 1) % MX;
}

int front(){
  return dat[head];
}

int back(){
  if(tail == 0) {
    return dat[MX - 1]; 
  }
  else{
    return dat[tail - 1];
  }
}

void test(){
  push(10); push(20); push(30);
  cout << front() << '\n'; // 10
  cout << back() << '\n'; // 30
  pop(); pop();
  push(15); push(25);
  cout << front() << '\n'; // 30
  cout << back() << '\n'; // 25
}

int main(void) {
  test();  
}
