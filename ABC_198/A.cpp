#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int answer;

  if (N == 1) {
    answer = 0;
  } else {
    answer = N - 1;
  }

  cout << answer << endl;
}
