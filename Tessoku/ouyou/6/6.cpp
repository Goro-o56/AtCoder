#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,A[100009],Q;
int L[100009], R[100009];

int wholesumWIN[100009], wholesumLOSE[100009];



int main() {
  cin >> N;

  for (int i = 1; i <= N; i ++){
    cin >> A[i];
  }  

  cin >> Q;

  for (int i = 1; i <= Q; i ++){
    cin >> L[i] >> R[i];
  }  

  //全体を足し合わせる
  for (int i = 1; i <= N; i ++){
     wholesumWIN[i] += wholesumWIN[i-1];
    if(A[i] == 1) {
     wholesumWIN[i] += 1;
    }

     wholesumLOSE[i] += wholesumLOSE[i-1];
    if(A[i] == 0) {
     wholesumLOSE[i] += 1;
    }
  }  


  //質問に応える
  for (int i = 1; i <= Q; i ++){
    //i個目の質問について
    int partialWIN, partialLOSE;
    partialWIN = wholesumWIN[R[i]] - wholesumWIN[L[i] - 1];
    partialLOSE = wholesumLOSE[R[i]] - wholesumLOSE[L[i] - 1];

    if(partialWIN > partialLOSE) cout << "win" << endl;
    else if (partialWIN == partialLOSE) cout << "draw" << endl;
    else  cout << "lose" << endl;

    
  }  

  return 0;
}