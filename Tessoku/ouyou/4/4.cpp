#include <iostream>
using namespace std;

int main() {
  string N;
  cin >> N;
  int Ans = 0;

  //8桁みて、各桁に対して場合分け
  for (int i = 0; i < N.size(); i++){
    int k = 0; //keta
    int kurai = 0;
    if (N[i] == '0') k = 0;
    if (N[i] == '1' ) kurai = N.size() - i - 1, k = 1;



    Ans +=  k* (1 << kurai);
  }
  
  
  cout << Ans << endl;

  return 0;
}