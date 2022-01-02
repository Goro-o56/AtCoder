#include <bits/stdc++.h>
using namespace std;
 
int main() {
  bitset<8> a("00011011");
  bitset<8> b("00110101");

  auto c = a&b; //aとbのビット演算 and

  cout << "1: " << c << endl;
  cout << "2: " << (c << 1) << endl;
  cout << "3: "<< (c << 2) << endl;
  cout << "4: "<< (c << 3) << endl;
  cout << "5: " << (c << 4) << endl;

  c <<= 4;
  cout << c << endl;

  c ^= bitset<8>("11010000"); //cと11010000のxor
  cout << "6: " << c << endl;

}