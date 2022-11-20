#include <iostream>
using namespace std;

int main() {
  int N;
  int A[101];
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  bool Ans = false;

  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j ++){
      for (int k = j + 1; k <= N; k ++){
        if(A[i]+A[j]+A[k] == 1000) Ans = true;
      }
    }  
  }
    if(Ans == true) cout << "Yes" << endl;
    else cout << "No" << endl;
  return 0;
}