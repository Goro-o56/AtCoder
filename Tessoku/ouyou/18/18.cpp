#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,S;
int A[69];

vector<int> Ans;
bool dp[69][10009];

int main() {
  cin >> N >> S;
  for (int i = 1; i <= N; i ++){
    cin >> A[i];
  }  

  //dp
  dp[0][0] = true;
  for (int i = 1; i <= S; i ++){
    dp[0][i] = false;
  }  

  for (int i = 1; i <= N; i ++){
    for (int j = 0; j <= S; j ++){
      if(j < A[i] ) {
        //Aだけ
        if(dp[i-1][j] == true) dp[i][j] = true;
        else dp[i][j] = false;
      }
      if(j >= A[i] ) {
        if(dp[i-1][j] == true || dp[i-1][j-A[i]] == true) dp[i][j] = true;
        else dp[i][j] == false;
      }
    }  
  }  

  //dpから逆算
  if(dp[N][S] == false) {cout << "-1" << endl; return 0;}

  int Place = S;  
  for (int i = N; i >= 1; i--){
    if(dp[i-1][Place] == true) Place = Place -0 ;
    else {
      Place = Place - A[i];
      Ans.push_back(i);
    };
  }  

  cout << Ans.size() << endl;
  reverse(Ans.begin(),Ans.end());
  for (int i = 0; i < Ans.size(); i ++){
    if(i >= 1) cout << " ";
    cout << Ans[i];
  }  
  cout << endl;



  return 0;
}