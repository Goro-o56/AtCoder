#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;


using namespace std;

vector<ll> Enumerate(vector<ll> A) {
  vector<ll> SumList;
  for (int i = 0; i < (1 << A.size()); i ++){
    ll sum = 0;
    for (int j = 0; j < A.size(); j ++){
      int wari = (1 << j);
      if((i / wari) % 2 == 1) sum += A[j];
    }  
    SumList.push_back(sum);
  }  
  return SumList;
}


ll N,K;
ll A[39];
int main() {
  //入力
  cin >> N >> K;
  for (int i = 1; i <= N; i ++){
    cin >> A[i];
  }  
  vector<ll> L1, L2;
  for (int i = 1; i <= N/2; i ++){
    L1.push_back(A[i]);
  }  

  for (int i = N/2 + 1; i <= N ; i ++){
    L2.push_back(A[i]);
  }  

  vector<ll> Sum1 = Enumerate(L1);
  vector<ll> Sum2 = Enumerate(L2);
  sort(Sum1.begin(), Sum1.end());
  sort(Sum2.begin(), Sum2.end());

  for (int i = 0; i < Sum1.size(); i ++){
    int pos = lower_bound(Sum2.begin(), Sum2.end(), K - Sum1[i]) - Sum2.begin();
    if( Sum2[pos] == K - Sum1[i]){
      cout << "Yes" << endl;
      return 0;
    }
  }  
  cout << "No" << endl;
  return 0;
}