#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  map<int, int> cnt;
  for (int x : A) {
    if (cnt.count(x)) {
      cnt.at(x)++; 
    }else {
      cnt[x] = 1;
    }
  }
  
  int max_cnt = 0;
  int ans = -1;
  for (int x : A) {
    if(max_cnt < cnt.at(x)){
      max_cnt = cnt.at(x);
      ans = x;
    }
  }

  cout << ans << "" << max_cnt << endl;

}