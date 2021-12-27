#include <bits/stdc++.h>
using namespace std;

int main() {
  //Setは重複のないデータのまとまりを扱うため
  //Keyだけのmapという感じ
  
  //↓の処理に有効
  //集合の中にある値が含まれるかを高速に計算する
  //集合の中に含まれる最大値、最小値を求める
  //値の種類数

  set<int> S;

  S.insert(3);
  S.insert(7);
  S.insert(8);
  S.insert(10);

  S.insert(3);

  cout << "size: " << S.size() << endl;
  //7が含まれるか => Set優位な処理
  if (S.count(7))  {
    cout << "found 7" << endl;
  }
  if (S.count(5)) {
    cout << "found 5" << endl;
  }
}