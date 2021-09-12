#include <bits/stdc++.h>
using namespace std;

int main() {
  int input;
  cin >> input;
  int h, m, s;
  h = input / 3600;
  input -= h * 3600;
  m = input / 60;
  input -= m * 60;
  s = input;

  cout << to_string(h) + ":" + to_string(m) + ":" + to_string(s) << endl;
  return 0;
}
