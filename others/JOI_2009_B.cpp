/*
*    author:  shinter_pres
*    created: 22.04.2021 18:50:52
*/

#include <bits/stdc++.h>

using namespace std;

int d, n, m;
vector<int> stores;
vector<int> customers;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> d >> n >> m;
  stores.resize(n);
  customers.resize(m);
  stores[0] = 0;

  for (int i = 0; i < n - 1; i++) {
    cin >> stores[i + 1];
  }
  for (int i = 0; i < m; i++) {
    cin >> customers[i];
  }

  sort(stores.begin(), stores.end());
  sort(customers.begin(), customers.end());

  // vector<int> test(5);
  // test.push_back(1);
  // test.push_back(2);
  // test.push_back(3);
  // test.push_back(5);
  // test.push_back(6);
  // auto test_itr = lower_bound(test.begin(), test.end(), 4);
  // int test_idx = test_itr - test.begin();
  // cout << "result: " << test[test_idx] << endl;

  int sum = 0;
  for (int i = 0; i < m; i++) {
    auto itr = lower_bound(stores.begin(), stores.end(), customers[i]);
    int idx = itr - stores.begin();
    if (idx  == stores.size()) {
      int result = min(abs(customers[i] - stores[stores.size() - 1]), abs(d - customers[i]));
      sum += result;
      // cout << "result a: " << result << endl;
    } else if (idx == 0) {
      int result = min(abs(stores[idx] - customers[i]), abs(customers[i] - stores[stores.size() - 1]));
      sum += result;
      // cout << "result b: " << result << endl;
    } else {
      int result = min(abs(stores[idx] - customers[i]), abs(customers[i] - stores[idx - 1]));
      sum += result;
      // cout << "result c: " << result << endl;
    }
  }

  cout << sum << endl;

  return 0;
}
