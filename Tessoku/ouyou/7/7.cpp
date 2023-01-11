#include <iostream>
using namespace std;

int T,N;
int L[500009], R[500009];

int B[500009], Ans[500009];
int main() {
  cin >> T;
  cin >> N;

  for (int i = 1; i <= N; i ++){
    cin >> L[i] >> R[i] ;
  }  

  for (int t = 1; t <= T; t ++){
    B[t] = 0;
  }  
  //差分を作る
  for (int i = 1; i <= N; i ++){
    B[L[i]] += 1;
    B[R[i]] -= 1;
  }  

  //累積和をとる
  Ans[0] = B[0];
  for (int i = 1 ; i <=  T ;  i ++){
    Ans[i] = Ans[i-1] + B[i];
  }  

  //質問に応える
  for (int i = 0 ; i < T; i ++){
    cout << Ans[i] << endl;
  }  
}