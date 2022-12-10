#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, A[100009], B[100009], dp[100009];

vector<int> Answer;

int main() {
  cin >> N;
  for (int i = 2; i <= N; i ++){
    cin >> A[i];
  }  
  for (int i = 3; i <= N; i ++){
    cin >> B[i];
  }  

  //dp
  dp[1] = 0;
  dp[2] = A[2];

  for (int i = 3; i <= N; i ++){
    dp[i] = min (dp[i-1] + A[i], dp[i-2] + B[i]);
  }  

  int place = N;

  while(true) {
    Answer.push_back(place);
    if(place == 1) break;

    if (dp[place-1] + A[place] == dp[place]) place = place -1;
    else place = place -2;

  }

  reverse(Answer.begin(), Answer.end());

  cout << Answer.size() << endl;
  for (int i = 0; i < Answer.size(); i ++){
    if( i >= 1) cout << " ";
    cout << Answer[i];
  }  
  cout << endl;
  

  return 0;
}