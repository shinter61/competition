#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int A[210];
  for (int i = 0; i < n; i++) cin >> A[i];


  int counter = 0;
  int flag = 0;
  while (flag == 0) {
    for (int i = 0; i < n; i++) {
      if (A[i] % 2 == 1) flag = 1;
    }

    if (flag == 1) break;

    for (int i = 0; i < n; i++) {
      A[i] /= 2;
    }

    counter++;
  }

  cout << counter << endl;
}
