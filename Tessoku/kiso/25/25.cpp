#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long  H,W;
char c[39][39];
long long dp[39][39];

int main() {
  cin >> H >> W;
  for (int i = 1; i <= H; i ++){
    for (int j = 1; j <= W; j ++){
      cin >> c[i][j];
    }  
  }  

  //動的計画法
  for (int i = 1; i <= H; i ++){
    for (int j = 1; j <= W; j ++){
      if (i == 1 && j == 1) {
        dp[i][j] = 1;
      }else{
        dp[i][j] = 0;
        if(i >= 2 && c[i-1][j] == '.') dp[i][j] += dp[i-1][j];
        if(i >= 2 && c[i][j-1] == '.') dp[i][j] += dp[i][j-1];
        
      }
    }  
  }  
  return 0;
}