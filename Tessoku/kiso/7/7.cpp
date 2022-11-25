#include <iostream>
using namespace std;

int D,N;

int L[100009],R[100009];

int B[100009], Ans[100009];


int main() {

  cin >> D;
  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    //配列の読み込み
    cin >> L[i] >> R[i];
  }
  
  //前日比を考える
  for (int i = 1; i <= N; i++)
  {
    B[L[i]] += 1;
    B[R[i] + 1] -= 1;
  }

  //累積和を取る
  Ans[0] = 0;
  for (int i = 1; i <= D; i ++){
  Ans[i] = Ans[i-1] + B[i];
  } 
  for (int i = 1; i <= D; i ++){
    cout << Ans[i]  << endl;
            
  }  
  
  return 0;
}