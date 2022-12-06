#include <iostream>
using namespace std;
int N;
int A[100009],B[100009],C[100009],D[100009];
int X[1509][1509], Z[1509][1509];
int main() {
  cin >> N;
  for (int i = 1; i <= N; i ++){
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }  

  for (int y = 0; y <= 1500; y ++){
    for (int x = 0; x <= 1500; x ++){
      Z[x][y] = 0;
    }  
  }  
  //各マスの重みづけ
  for (int i = 1; i <= N; i ++){
    Z[A[i]][B[i]] += 1;
    Z[C[i] ][D[i] ] += 1;

    Z[C[i] ][B[i]] -= 1;
    Z[A[i]][D[i] ] -= 1;
  }   

  //累積和を求める
  for (int i = 0; i <= 1500; i ++){
    for (int j = 1; j <= 1500; j ++){
      Z[i][j] = Z[i][j-1] + Z[i][j];
    }  
  }   

  for (int i = 1; i <= 1500; i ++){
    for (int j = 0; j <= 1500; j ++){
      Z[i][j] = Z[i-1][j] + Z[i][j];
    }  
  }  
  //横方向に足す

  int Ans = 0;
  for (int i = 0; i <= 1500; i ++){
    for (int j = 0; j <= 1500; j ++){
      if(Z[i][j] >= 1) Ans += 1;
    }  
  }  
  cout << Ans << endl;


  return 0;
}