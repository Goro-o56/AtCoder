#include <iostream>
using namespace std;
int N;
int P[1509][1509];
int Z[1509][1509];
int X,Y;
int Q;
int A[1509], B[1509], C[1509], D[1509];
int main() {
  cin >> N;
  
  int p_num = 1509;
  
  for (int x = 1; x <= p_num; x ++){
    for (int y = 1; y <= p_num; y ++){
      //2次元配列の初期化 
      //x*yの座標
      P[x][y] = 0;
      //累積和の2次元配列
      Z[x][y] = 0;

    }  
  }

  for (int i = 1; i <= N; i ++){
    cin >> X >> Y;
    P[X][Y] = 1;
  }

  //P上の累積和を取る

  //横の累積和
  for (int x = 1; x <= p_num; x ++){
    for (int y = 1; y <= p_num; y ++){
      Z[x][y] = Z[x-1][y] + P[x][y];
    }  
  }  

  //縦の累積和
  for (int y = 1; y <= p_num; y ++){
    for (int x = 1; x <= p_num; x ++){
      Z[x][y] = Z[x][y-1] + Z[x][y];
    }  
  }  

  //質問に応える
  cin >> Q;
  for (int i = 1; i <= Q; i ++){
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }  
  
  for (int i = 1; i <= Q; i ++){
    Z[C[i]][D[i]] + Z[A[i] - 1][B[i] - 1] - Z[C[i]][B[i] - 1] - Z[A[i] - 1][D[i]];
  } 

  return 0;
}