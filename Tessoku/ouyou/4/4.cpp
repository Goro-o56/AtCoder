#include <iostream>
using namespace std;

int main() {
  string N;
  cin >> N;
  int Ans = 0;

  for (int i = 0; i < N.size(); i ++){
    //0のくらいから見ていく
    if(N[i] == '1')  Ans += (1 << N.size() - i - 1);
    else Ans += 0;
  }  
  
  
  cout << Ans << endl;

  return 0;
}