#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double R, X, Y;
  cin >> R >> X >> Y;
  int answer = 0;
  double d;
  d = sqrt(X * X + Y * Y);

  if (d < R) {
    answer = 2;
  } else if (fmod(d, R) == 0.0) {
    answer += d / R;
  } else {
    answer += d / R;
    answer += 1;
  }

  cout << answer << endl;
}
