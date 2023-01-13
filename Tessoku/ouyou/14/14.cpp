#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE_OF_ARRAY(array)    (sizeof(array)/sizeof(array[0]))

using namespace std;
int N,K;
int A[39];

int P[909],Q[909];

int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; i ++){
    cin >> N;
  }  

  //P,Qの計算
  for (int i = 1; i <= N/2; i ++){
    for (int j = i + 1; j <= N/2; j ++){
      P[i*j] = A[i] * A[j];
    }  
  }  

  for (int i = N/2; i <= N*N; i ++){
    for (int j = i + 1; j <= N*N; j ++){
      Q[i*j] = A[i] * A[j];
    }  
  }  


  //探索
  sort(Q + 1, Q + (N*N) + 1);
  sort(P+(N*N)/2+1 , P+(N*N) +1);

  bool Ans = false;
  for (int i = 1; i <= (N*N)/2; i ++){
    int pos = lower_bound(Q + 1, Q + (N * N) + 1, K - P[i]) - Q;
    if(Q[pos] == K - P[i] && pos < SIZE_OF_ARRAY(P) ) {
      cout << "Yes" << endl;
      return 0;
    };
  }  

 cout << "No" << endl;
  
  return 0;
}