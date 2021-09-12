#include <iostream>
using namespace std;

int main() {
  int N, Y;
  cin >> N >> Y;

  int x = -1, y = -1, z = -1;

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= (N - i); j++) {
      for (int k = 0; k <= (N - i - j); k++) {
        if ((10000 * i + 5000 * j + 1000 * k == Y) and ((i + j + k) == N)) {
          x = i;
          y = j;
          z = k;
          break;
        }
      }
    }
  }

  cout << x << " " << y << " " << z << endl;
}
