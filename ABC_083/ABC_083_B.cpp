#include <iostream>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  int sum = 0;
  for (int i = 1; i <= N; i++) {
    int ma, th, ha, te, o;
    ma = i / 10000;
    th = i % 10000 / 1000;
    ha = i % 1000 / 100;
    te = i % 100 / 10;
    o = i % 10;

    int keta_sum = ma + th + ha + te + o;

    if (keta_sum >= A and keta_sum <= B) {
      sum += i;
    }
  }

  cout << sum << endl;
}
