#include <iostream>
using namespace std;

int main() {
  int Ans = 0;
  int N, K = 0;
  cin >> N >> K;

  for (int i = 1; i <= N; i++) //赤のループ
  {
      for (int j = 1; j <= N; j++) //青のループ
      {
        //i, j からkを求める 
        int Z = K - (i + j);
        if(Z >= 1 && Z <= N) Ans += 1;        
      }
      
  }

  cout << Ans << endl; 
  return 0;
}