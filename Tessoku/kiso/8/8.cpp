#include <iostream>
using namespace std;
int H,W;
int X[1509][1509];
int Q;
int LeftTopX[100009], LeftTopY[100009], RightBotX[100009], RightBotY[100009];
int Z[1509][1509]; 

int main() {
  //input
  cin >> H >> W;

  //2次元の配列
  for (int i = 1; i <= H; i ++){
    for (int j = 1; j <= W; j ++){
      cin >> X[i][j];
    }  
  } 

  cin >> Q;

  for (int i = 1; i <= Q; i ++){
    cin >> LeftTopX[i] >> LeftTopY[i] >> RightBotX[i] >> RightBotY[i]; 
  }

  //2次元配列Zの初期化
  for (int i = 0; i <= H; i ++){
    for (int j = 0; j <= W; j ++){

      Z[i][j] = 0; //累積和
    }  
  }  

  //横方向に累積和を取る まずi(∈H)を固定 
  for (int i = 1; i <= H; i ++){
    for (int j = 1; j <= W; j ++){
      Z[i][j] = Z[i][j-1] + X[i][j];
    }  
  }  

  //縦方向に累積和を取る まずj(∈W)を固定
  for (int j = 1; j <= W; j ++){
    for (int i = 1; i <= H; i ++){
      Z[i][j] = Z[i-1][j] + Z[i][j];
    }  
  }  

  //質問に応える Q回のループ
  for (int i = 1; i <= Q; i ++){
    //
    int Ans = Z[RightBotX[i]][RightBotY[i]]+Z[LeftTopX[i] - 1][LeftTopY[i] - 1]
    - Z[LeftTopX[i] - 1][RightBotY[i]] - Z[RightBotX[i]][LeftTopY[i] - 1];

    cout << Ans << endl;
  }  
  return 0;
}