#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "Hello, ";
  goto SKIP;
  cout << "world" << endl; //飛ばされる ラベル先まで
SKIP:
  cout << "AtCoder" << endl;
}