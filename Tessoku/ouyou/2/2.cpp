#include <iostream>
using namespace std;

int A, B;
int main() {
  cin >> A >> B;

  bool Ans = false;
  //AからBまでの整数を見る
  for (int i = A; i <= B; i++) {
    //100がiで割り切れたら出力
    if(100%i == 0) Ans = true;
  }
  
  if(Ans == true) cout << "Yes" << endl;
  else cout << "No" << endl; 
  return 0;
}

