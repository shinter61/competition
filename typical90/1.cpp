/*
*    author:  shinter_pres
*    created: 16.07.2021 05:57:32
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, L, K;
  cin >> N >> L;
  cin >> K;
  vector<int> a(N), pieces(N+1);
  rep(i, N) { cin >> a[i]; }
  rep(i, N+1) {
    if (i == 0) {
      pieces[i] = a[i] - 0;
    } else if (i == N) {
      pieces[i] = L - a[i-1];
    } else {
      pieces[i] = a[i] - a[i-1];
    }
  }

  int min = 0, max = L, mid = (min+max)/2;
  while (max - min > 1) {
    int piece_len = 0;
    int piece_cnt = 0;
    for (auto piece: pieces) {
      piece_len += piece;
      if (piece_len >= mid) {
        piece_len = 0;
        piece_cnt++;
      }

      if (piece_cnt >= K+1) { break; }
    }

    // cout << "max: " << max << " min: " << min << endl;
    if (piece_cnt >= K+1 && piece_len == 0) {
      min = mid;
    } else {
      max = mid;
    }
    mid = (min+max)/2;
  }

  cout << mid << endl;

  return 0;
}
