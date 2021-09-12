#include <bits/stdc++.h>
using namespace std;

int main() {
  vector< vector <int> > input(1000, vector<int>(2));
  for (int i = 0; i < input.size(); i++) {
    cin >> input[i][0] >> input[i][1];
    cout << "hello" << endl;
    if (input[i][0] == 0 && input[i][1] == 0) break;
    cout << "world" << endl;
  }

  cout << "this is interval" << endl;

  for (int i = 0; i < input.size(); i++) {
    cout << "are you ready" << endl;
    if (input[i][0] == 0 && input[i][1] == 0) break;
    cout << "whooooo" << endl;
    for (int j = 0; j < input[i][0]; j++) {
      string s = "";
      for (int k = 0; j < input[i][1]; k++) {
        s += "#";
      }
      cout << s << endl;
    }
    cout << "\n" << endl;
  }
  return 0;
}
