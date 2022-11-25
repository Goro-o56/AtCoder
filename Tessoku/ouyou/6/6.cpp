#include <iostream>
using namespace std;

int N,Q;
int A[100009],L[100009],R[100009], WIN[100009], LOSE[100009];

int main() {

  //input
  cin >> N;
  for (int i = 1; i <= N ; i++)
  {
    cin >> A[i];
  }

  cin >> Q;

  for (int i = 1; i <= Q; i++)
  {
    cin >> L[i] >> R[i];
  }

  //累積和を求める 勝ち数と負け数
  WIN[0] = 0;
  LOSE[0] = 0;

  for (int i = 1; i <= N; i++)
  {
    WIN[i] = WIN[i-1];
    if (A[i] == 1) {
      //勝っている場合
      WIN[i] += 1 ;
    }; 
    
    LOSE[i] = LOSE[i-1];
    if (A[i] == 0) {
      //負けている場合
      LOSE[i] += 1;
    };

    
  }

  //質問に応える L,Rの期間の内多い方を採用する 比較はQ回
  for (int i = 1; i <= Q; i++)
  {
 
    //累積和から差分を求める。
    //勝ち数、負け数の部分和
    int partialWINS = WIN[R[i]] - WIN[L[i] - 1];

    int partialLOSES = LOSE[R[i]] - LOSE[L[i] - 1];

    if(partialWINS > partialLOSES)  cout << "win" << endl; //勝ち
    else if(partialWINS == partialLOSES) cout << "draw" << endl; //引き分け
    else cout << "lose" << endl; //負け

    
 }
  
  

  
  return 0;
}

