#include <bits/stdc++.h>
using namespace std;

//コピーコンストラクタ

struct MyPair {
  int x;
  string y;

  //constructor
  MyPair() {
    cout << "normal constructor called" << endl;
  }
  
  MyPair(const MyPair &old) {
    cout << "copy constructor called" << endl;
    
    x = old.x + 1;
    y = old.y + " new";
  }
};

int main() {
  MyPair p;
  p.x = 12345;
  p.y = "hello";
  
  cout << "p.x = " << p.x << endl;
  cout << "p.y = " << p.y << endl;

  MyPair q(p);
  cout << "q.x = " << q.x << endl;
  cout << "q.y = " << q.y << endl;

  MyPair r = q;
  cout << "r.x = " << r.x << endl;
  cout << "r.y = " << r.y << endl;
}