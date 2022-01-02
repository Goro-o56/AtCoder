#include <bits/stdc++.h>
using namespace std;
 
int main() { 
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  bool ans = false;
  
  //全ての選び方を試して、総和がKになるものがあるかを調べる
  for (int tmp = 0; tmp < (1 << 20); tmp++) {
    bitset<20> s(tmp); //20個の数についてを20ビットであらわす

    //ビット列の1ビットに対応する整数をAから選びsumに足す
    int sum = 0;
    for (int i = 0; i < N; i++) {
      if(s.test(i)) {
        sum += A.at(i);
      }
    }
    if (sum == K) {
      ans = true;
    }
  }

  if (ans) {
    cout << "YES" << endl;
  }else {
    cout << "NO" <<endl;
  }

}