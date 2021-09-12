#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;

  string s;
  string s_copy;
  s = to_string(N);
  s_copy = s;

  for (int i = ((int)s_copy.size()) - 1; i >= 0; --i) {
    if (s_copy[i] == '0') {
      s.insert(0, "0");
    } else {
      break;
    }
  }


  bool is_kaibun = true;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] != s[(int)s.size() - 1 - i]) {
      is_kaibun = false;
      break;
    }
  }

  if (is_kaibun) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
