#include <bits/stdc++.h>
using namespace std;

int main() {
  //出現回数が最も多い値とその出現回数
  //配列をしまう
  map<int, int> m;
  int N = 0;
  set<int> S ;

  cin >> N ;
  for(int i = 0; i < N; i++) {
    //mにkey(=i),valueをしまう
    cin >> m[i];
    S.insert(m[i]);
  }

  //辞書の中で最も多く出現する物を総なめする
  map<int, int> ans; //カウント用のmap
  int cnt ;

  for(int i = 0; i < S.size() ; i++) {//種類をそうなめ
    cnt = 0;
    for(int j = 0; j < N; j++) {
      //ある最小の種類S[i]を固定した中で、m[j]が含まれるか
        if(*begin(S) == m[j]){ //最小値から取っていけば順に進められる
          //最小のS[i] を見て、同じ要素があればm[j]とcntを合わせて覚える
          cnt++;
          ans[m[j]] = cnt;
        }
      }
    }
    S.erase(*begin(S));
  }

  


  

}