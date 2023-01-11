#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int A[100009];
int D;
int L[100009],R[100009];

int P[100009],Q[100009];

int main() {
  cin >> N;
  
  for (int i = 1; i <= N; i ++){
    cin >> A[i];
  }  

  cin >> D;

  for (int d = 1; d <= D; d ++){
    cin >> L[d] >> R[d];
  }  

  //P[d], Q[d]を求める
  P[1] = A[1];
  for (int d = 2; d <= N; d ++){
    P[d] = max(P[d-1], A[d]);
  }  
  Q[N] = A[N];
  for (int d = N - 1; d >= 1; d --){
    Q[d] = max(Q[d+1], A[d]);
  }  


  //それぞれの日について解答
  for (int d = 1; d <= D; d ++){
    cout << max(P[L[d]-1], Q[R[d]+1]) << endl;
  }  
  

  
  return 0;
}