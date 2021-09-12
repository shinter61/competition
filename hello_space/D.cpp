/*
*    author:  shinter_pres
*    created: 01.05.2021 21:15:49
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  string s, t = "";
  cin >> s;

  bool hanten = false;
  deque<char> q;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'R') {
      hanten = !hanten;
    } else {
      if (hanten) {
        q.push_front(s[i]);
      } else {
        q.push_back(s[i]);
      }
    }
  }

  if (hanten) {
    reverse(q.begin(), q.end());
  }

  for (auto qc: q) {
    if (!t.empty() && t.back() == qc) t.pop_back();
    else t.push_back(qc);
  }

  cout << t << endl;

  return 0;
}
