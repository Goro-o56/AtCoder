#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int A[1509],B[1509],C[1509],D[1509];

int P[1509][1509];

int Z[1509][1509];



int main() {
  cin >> N;
  for (int i = 1; i <= N; i ++){
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }  

  for (int x = 0; x <= 1500; x ++){
    for (int y = 0; y <= 1500; y ++){
      Z[x][y] = 0;
    }  
  }    

  for (int i = 1; i <= N; i ++){
    Z[C[i]][D[i]] += 1;
    Z[A[i]][B[i]] += 1;

    Z[C[i]][B[i]] -= 1;
    Z[A[i]][D[i]] -= 1;
  }  

  //横の累積和
  for (int y = 0; y <= 1500; y ++){
    for (int x = 1; x <= 1500; x ++){
      Z[x][y] = Z[x-1][y] + Z[x][y];
    }  
  }  

  for (int x = 0; x <= 1500; x ++){
    for (int y = 1; y <= 1500; y ++){
      Z[x][y] = Z[x][y-1] + Z[x][y];
    }  
  }  

  int Ans = 0;
  for (int i = 0; i <= 1500; i ++){
    for (int j = 0; j <= 1500; j ++){
      if(Z[i][j] >= 1) Ans += 1;
    }  
  }  

  cout << Ans << endl;

  
  return 0;
}