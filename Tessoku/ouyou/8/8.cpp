#include <iostream>
using namespace std;
int N;
int P[1509][1509];
int Z[1509][1509];
int X[100009],Y[100009];
int Q;
int A[100009], B[100009], C[100009], D[100009];
int main() {
  cin >> N;
  for (int i = 1; i <= N; i ++){
    cin >> X[i] >> Y[i];
  }

  cin >> Q;
  for (int i = 1; i <= Q; i ++){
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }  
  
  //各点を入力する
  for (int i = 1; i <= N; i ++){
    P[X[i]][Y[i]] += 1;
  } 
  

  //累積和
  for (int x = 0; x <= 1500; x ++){
    for (int y = 0; y <= 1500; y ++){
      Z[x][y] = 0;
    }  
  }  
  //横の累積和
  for (int y = 1; y <= 1500 ; y ++){
    for (int x = 1; x <= 1500; x ++){
      Z[x][y] = Z[x-1][y] + P[x][y];
    }  
  }  

  //縦の累積和
  for (int x = 1; x <= 1500; x ++){
    for (int y = 1; y <= 1500; y ++){
      Z[x][y] = Z[x][y-1] + Z[x][y];
    }  
  }  

  for (int i = 1; i <= Q; i ++){
    int Ans = Z[C[i]][D[i]] + Z[A[i]-1][B[i]-1] - Z[C[i]][B[i]-1] - Z[A[i]-1][D[i]];
    cout << Ans << endl;
  }  



  return 0;
}