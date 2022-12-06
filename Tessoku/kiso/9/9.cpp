#include <iostream>
using namespace std;
int H,W,N;
int A[100009],B[100009],C[100009],D[100009];

int X[1509][1509]; //マス目あたりの重み
int Z[1509][1509]; //累積和
int main() {
  cin >> H >> W >> N ;
  for (int i = 1; i <= N; i ++){
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }  

  //マス目あたりの重みづけ
  for (int i = 1; i <= N; i ++){
    X[A[i]][B[i]] += 1;
    X[C[i] + 1][D[i] + 1] +=1;
    X[C[i] + 1][B[i]] -=1;
    X[A[i]][D[i] + 1] -=1;
  }  

  for (int y = 0; y <= H; y ++){
    for (int x = 0; x <= W; x ++){
      Z[y][x] = 0;
    }  
  }  

  //累積和 横向き
  for (int y = 1; y <= H; y ++){
    for (int x = 1; x <= W; x ++){
      Z[y][x] = Z[y][x-1]+X[y][x];
    }  
  }  
  //累積和 縦向き
  for (int x = 1; x <= W; x ++){
    for (int y = 1; y <= H; y ++){
        Z[y][x] = Z[y-1][x] + Z[y][x];
    }  
  }

  //質問に応える
  for (int y = 1; y <= H; y ++){
    for (int x = 1; x <= W; x ++){
      if(x >= 2) cout << " ";
      cout << Z[y][x];
    }  
    cout << endl;
  }  





  return 0;
}