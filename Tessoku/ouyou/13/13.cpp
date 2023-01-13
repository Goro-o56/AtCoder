#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,K;
int A[100009];

int B[100009];

int R[100009];

  //2つの区間の和
  int sum(int s, int t){
    return (B[t] - B[s-1]);
  }

int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; i ++){
    cin >> A[i];
  }  

  for (int i = 1; i <= N; i ++){
    R[i] = 0;
  }  

  //品物についての累積和
  B[0] = 0;
  for (int i = 1; i <= N; i ++){
    B[i] = B[i-1] + A[i];
  }  


  //K円以内に収まる買い方

  for (int s = 1; s <= N; s ++){
    if(s == 1) R[s] = 0;
    else R[s] = R[s-1];

    while(sum(s, R[s] + 1) <= K && R[s] < N ) {
      R[s] ++;
    }

  }  
  int Ans = 0;
  for (int s = 1; s <= N; s ++){
    Ans += R[s] - s + 1;
  }  

  cout << Ans << endl;
  return 0;
}