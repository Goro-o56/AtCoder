#include <iostream>
using namespace std;
#include <algorithm>
int N,K;
int A[1009],B[1009],C[1009],D[1009];
int P[1000009],Q[1000009];

int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; i ++){
    cin >> A[i];
  }  
  for (int i = 1; i <= N; i ++){
    cin >> B[i];
  } 
  for (int i = 1; i <= N; i ++){
    cin >> C[i];
  }
  for (int i = 1; i <= N; i ++){
    cin >> D[i];
  } 
  //P,Q are sums of two arrays 
  for (int i = 1; i <= N; i ++){
     for (int j = 1; j <= N; j ++){
        P[(j-1)*N + i] = A[i] + B[j];
    }  
  }  
  
  for (int i = 1; i <= N; i ++){
    for (int j = 1; j <= N; j ++){
      Q[(j-1)*N + i] = C[i] + D[j];
    }  
  }  

  //配列Qを小さい順にソート
  sort(Q + 1, Q + (N * N) + 1);

  for (int i = 1; i <= N*N; i ++){
    int pos1 = lower_bound(Q + 1, Q + (N*N) + 1, K - P[i]) -Q;
    if(pos1 <= N*N && Q[pos1] == K - P[i]) {
      cout << "Yes" << endl;
      return 0;
    }
  }  

  cout << "No" << endl;
  return 0;
}