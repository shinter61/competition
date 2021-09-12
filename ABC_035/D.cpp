#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n, m, t;
  cin >> n >> m >> t;
  vector<int> cost_list(n);
  for (int i = 0; i < n; i++) cin >> cost_list[i];
  vector<int> a(m), b(m), c(m);
  for (int i = 0; i < m; i++) cin >> a[i] >> b[i] >> c[i];
  return EXIT_SUCCESS;
}
