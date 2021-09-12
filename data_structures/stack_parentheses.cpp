#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(const string &S) {
  stack<int> st;
  vector<pair<int, int>> ps;

  for (int i = 0; i < (int)S.size(); i++) {
    if (S[i] == '(') { st.push(i); }
    else {
      if (st.empty()) {
        cout << "error" << endl;
        return false;
      }

      int t = st.top();
      st.pop();
      ps.push_back(make_pair(t, i));
    }
  }

  if (!st.empty()) {
    cout << "too many (" << endl;
    return false;
  }

  sort(ps.begin(), ps.end());
  for (int i = 0; i < (int)ps.size(); i++) {
    if (i) cout << ", ";
    cout << "(" << ps[i].first << ", " << ps[i].second << ")";
  }
  cout << endl;
  return true;
}

int main() {
  check("((()))()");
  return EXIT_SUCCESS;
}
