#include <bits/stdc++.h>
using namespace std;

struct MyPair  {
  int x;
  string y;

  MyPair() {
    cout << "初期化無し" << endl;
  }

  MyPair(int x_) {
    cout << "xのみ初期化" << endl;
    x = x_;
  }

  MyPair(int x_,string y_) {
    cout << "x,yともに初期化" << endl;
    x = x_;
    y = y_;
  }
};

int main() {
  MyPair p;
  cout << "p.x = " << p.x << endl;
  cout << "p.y = " << p.y << endl;

  MyPair q(6789);
  cout << "q.x = " << q.x << endl;
  cout << "q.y = " << q.y << endl;

  MyPair r(11111, "good bye");
  cout << "r.x = " << r.x << endl;
  cout << "r.y = " << r.y << endl;
 }