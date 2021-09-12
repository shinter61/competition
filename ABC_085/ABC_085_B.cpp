#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N;
  int d[110];

  cin >> N;
  for (int i = 0; i < N; i++) cin >> d[i];

  sort(d, d + N, greater<int>());

  int x = 1;
  int prev;

  prev = d[0];
  for (int i = 0; i < N; i++) {
    if (prev > d[i]) {
      x += 1;
    }
    prev = d[i];
  }

  cout << x << endl;
}
