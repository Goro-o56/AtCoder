#include <iostream>
using namespace std;

int N,K;
int A[100009];


bool check(long long x) {
  long long sum = 0;
  for (int i = 1; i <= N; i++) sum += x/A[i];
  if (sum >= K)return true;
  return false;
}

int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; i ++){
    cin >> A[i];
  }  

  //二分探索 応えに対して
  long long Left = 1, Right = 1'000'000'000;
  while(Left < Right) {
    long long Mid = (Left + Right)/2;
    bool Answer = check(Mid);
    if(Answer == false) Left = Mid + 1;
    if(Answer == true) Right = Mid;
  }

  cout << Left << endl;
  return 0;
}

