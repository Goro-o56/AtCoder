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

  //差分を考える
  for (int i = 1; i <= N; i ++){
    B[L[i]] += 1;
    B[R[i]] -= 1;
  }  

  //累積和
  Ans[0] = B[0];
  for (int t = 0; t <= T; t ++){
    Ans[t] = Ans[t-1] + B[t];
  }  

  //質問に応える
  for (int t = 0; t < T; t ++){
    cout << Ans[t] << endl;  
  }  

}