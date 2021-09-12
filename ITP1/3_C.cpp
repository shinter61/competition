#include <bits/stdc++.h>
using namespace std;

int main() {
  vector< vector<int> > input(3000, vector<int>(2));
  for (int i = 0; i < input.size(); i++) {
    cin >> input[i][0] >> input[i][1];
    if (input[i][0] == 0 && input[i][1] == 0) break;
  }

  for (int i = 0; i < input.size(); i++) {
    if (input[i][0] == 0 && input[i][1] == 0) break;

    if (input[i][0] > input[i][1]) {
      cout << input[i][1] << " " << input[i][0] << endl;
    } else {
      cout << input[i][0] << " " << input[i][1] << endl;
    }
  }
  return 0;
}
