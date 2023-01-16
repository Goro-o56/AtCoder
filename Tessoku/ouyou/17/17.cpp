#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int h[100009];
int dp[100009];

int K;
int P[100009];

vector<int> Answer;


int main() {
  //input
  cin >> N;
  for (int i = 1; i <= N; i ++){
    cin >> h[i];
  }  

  //dp
  dp[1] = 0;
  dp[2] = abs(h[2] - h[1]);
  
  for (int i = 3; i <= N; i ++){
    dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
  }  

  //応えの復元
  int Place = N;
  while(true) {
    Answer.push_back(Place);
    if(Place == 1) break;

    if(dp[Place - 1] + abs(h[Place] - h[Place-1]) == dp[Place]) Place = Place - 1;
    else Place = Place - 2;
  }

  reverse(Answer.begin(), Answer.end());

  cout << Answer.size() << endl;

  for (int i = 0; i < Answer.size(); i ++){
    if (i >= 1) cout << " ";
    cout << Answer[i];
  }  

  cout << endl;
  return 0;
}