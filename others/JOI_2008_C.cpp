/*
*    author:  shinter_pres
*    created: 26.04.2021 22:31:38
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<long long> p, possib;
long long s = 0;
long long pa, pb, pc, pd;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  p.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  sort(p.begin(), p.end());

  for (int a = -1; a < n; a++) {
    pa = a == -1 ? 0 : p[a];
    for (int b = -1; b < n; b++) {
      pb = b == -1 ? 0 : p[b];
      possib.push_back(pa + pb);
    }
  }

  sort(possib.begin(), possib.end());

  for (int i = 0; i < possib.size(); i++) {
    pc = possib[i];
    auto itr = upper_bound(possib.begin(), possib.end(), m - pc);
    int idx = itr - possib.begin();

    if (idx == possib.size()) continue;
    else if (idx - 1 < 0) continue;
    else pd = possib[idx - 1];

    long long zantei_s = pc + pd;
    if (zantei_s > s && zantei_s <= m) s = zantei_s;
  }

  cout << s << endl;

  return 0;
}
