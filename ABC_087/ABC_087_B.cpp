#include <iostream>
using namespace std;

int main() {
  int a, b, c, X;

  cin >> a; // 500
  cin >> b; // 100
  cin >> c; // 50
  cin >> X;

  int counter = 0;

  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      for (int k = 0; k <= c; k++) {
        if (X == (500 * i + 100 * j + 50 * k)) {
          counter++;
        }
      }
    }
  }

  cout << counter << endl;
}
