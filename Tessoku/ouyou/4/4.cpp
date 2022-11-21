#include <iostream>
using namespace std;

int main() {
  string N;
  cin >> N;
  int Ans = 0;

  //8桁みて、各桁に対して場合分け
  for (int i = 0; i < N.size(); i++){
    int keta;
    int kurai = (1 << (N.size() - 1 - i));
    if(N[i] == '0') keta = 0;
    if(N[i] == '1') keta = 1;
    Ans += keta * kurai;
  }
  
  cout << Ans << endl;

  return 0;
}