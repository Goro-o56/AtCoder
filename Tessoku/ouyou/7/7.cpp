#include <iostream>
using namespace std;

int T, N;
int L[500009], R[500009];
int B[500009], Ans[500009];

int main() {
  cin >> T;
  cin >> N;

  for (int i = 1; i <= N; i ++){
    cin >> L[i] >> R[i];
  }  

  for (int t = 1; t <= T; t ++){
    B[t] = 0;
  }  
  //出勤と退勤の入力
  for (int i = 1; i <= N; i ++){
    B[L[i]] += 1; //一人追加
    B[R[i]] -= 1; //一人減少
  }  

  //累積和
  Ans[0] = B[0];
  for (int t = 1; t <= T; t ++){
    //出勤から退勤までの累積和を取る
    Ans[t] = Ans[t-1] + B[t];
  }  
  //質問に応える
  for (int t = 0; t < T; t ++){
    cout << Ans[t]  << endl;
            
  }  

  return 0;
}