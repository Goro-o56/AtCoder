#include <bits/stdc++.h>
using namespace std;
 
int main() { 
  //2のk乗を得るために1<<kと書くことがある
  for (int tmp = 0; tmp < (1 << 3); tmp++) {
    bitset<3> s(tmp);
    cout << s << endl;
  }
}