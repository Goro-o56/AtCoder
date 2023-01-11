#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int A,B;

int main() {
  cin >> A >> B;

  bool Ans = false;
  //100の約数が存在する
  for (int i = A; i <= B; i++)
  {
    //
    if(100 % i == 0) Ans = true;
  }
  
    if(Ans == true) cout << "Yes" << endl;
    else cout << "No" << endl;
  return 0;
}