#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int A[100009];
int dp[100009],LEN = 0, L[100009];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i ++){
    cin >> A[i];
  }  

  for (int i = 1; i <= N; i ++){
    int pos = lower_bound(L + 1, L + LEN + 1, A[i]) - L;
    dp[i] = pos;

    L[dp[i]] = A[i];
    if(dp[i] > LEN) LEN += 1;
  }  

  cout << LEN << endl;

  return 0;
}