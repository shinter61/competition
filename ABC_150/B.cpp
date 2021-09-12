#include <bits/stdc++.h>
using namespace std;

string build_str(int num) {
  string three_str = "";
  if (num < 10) {
    three_str += "0";
    three_str += "0";
    three_str += to_string(num);
  } else if (num < 100) {
    three_str += "0";
    three_str += to_string(num / 10);
    three_str += to_string(num % 10);
  } else {
    three_str += to_string(num / 100);
    three_str += to_string((num % 100) / 10);
    three_str += to_string((num % 100) % 10);
  }

  return three_str;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<bool> list(1000, false);
  string num_str;
  for (int i = 0; i < 1000; i++) {
    num_str = build_str(i);
    for (auto c: s) {
      bool first_found = false, second_found = false;
      if (c == num_str[0] && !first_found && !second_found) {
        first_found = true;
        continue;
      }
      if (c == num_str[1] && first_found && !second_found) {
        second_found = true;
        continue;
      }
      if (c == num_str[2] && first_found && second_found) {
        list[i] = true;
        break;
      }
    }
  }
  int cnt = 0;
  for (auto found: list) {
    if (found) cnt++;
  }
  cout << cnt << endl;

  return 0;
}
