#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N,S;
int A[69];
bool dp[69][10009];

int main() {
  cin >> N >> S;
  for (int i = 1; i <= N; i ++){
    cin >> A[i];
  }

  for (int i = 1; i <= S; i ++){
    dp[0][i] = false;
  }  

  for (int i = 1; i <= N; i ++){
    for (int j = 0; j <= S; j ++){
      if(j < A[i]){
        if(dp[i-1][j] == true) dp[i][j] = true;
        else dp[i][j] = false;
      }
      if(j >= A[i]){
        if(dp[i-1][j] == true || dp[i-1][j] == true) dp[i][j] = true;
        else dp[i][j] = false;
      }
    }  
  }  


  return 0;
}