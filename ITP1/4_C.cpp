#include <bits/stdc++.h>
using namespace std;

int main() {
  vector< vector<string> > x(3000, vector<string>(3));
  for (int i = 0; i < x.size(); i++) {
    cin >> x[i][0] >> x[i][1] >> x[i][2];
    if (x[i][1] == "?") break;
  }
  for (int i = 0; i < x.size(); i++) {
    if (x[i][1] == "?") break;

    if (x[i][1] == "+") {
      cout << stoi(x[i][0]) + stoi(x[i][2]) << endl; 
    } else if (x[i][1] == "-") {
      cout << stoi(x[i][0]) - stoi(x[i][2]) << endl; 
    } else if (x[i][1] == "*") {
      cout << stoi(x[i][0]) * stoi(x[i][2]) << endl; 
    } else if (x[i][1] == "/") {
      cout << stoi(x[i][0]) / stoi(x[i][2]) << endl; 
    }
  }
  return 0;
}
