/*
*    author:  shinter_pres
*    created: 24.04.2021 20:43:39
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, Q;
  string S;
  vector<int> T, A, B;
  cin >> N;
  cin >> S;
  cin >> Q;
  T.resize(Q);
  A.resize(Q);
  B.resize(Q);
  for (int i = 0; i < Q; i++) {
    cin >> T[i] >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }

  string z, k;
  k = S.substr(N);
  S.erase(N);
  z = S;

  for (int i = 0; i < Q; i++) {
    if (T[i] == 1) {
      char tmp;
      if (A[i] < N) {
        tmp = z[A[i]];
        if (B[i] < N) {
          z[A[i]] = z[B[i]];
          z[B[i]] = tmp;
        } else {
          z[A[i]] = k[B[i] - N];
          k[B[i] - N] = tmp;
        }
      } else {
        tmp = k[A[i] - N];
        k[A[i] - N] = k[B[i] - N];
        k[B[i] - N] = tmp;
      }
    } else {
      swap(z, k);
    }
  }

  cout << z + k << endl;

  return 0;
}
