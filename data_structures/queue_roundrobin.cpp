#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  queue<pair<string, int>> que;

  for (int i = 0; i < n; i++) {
    string name;
    int time;
    cin >> name >> time;
    que.push(make_pair(name, time));
  }

  int total_time = 0;
  while (!que.empty()) {
    if (que.front().second > q) {
      auto new_pair = que.front();
      new_pair.second -= q;
      que.pop();
      que.push(new_pair);
      total_time += q;
    } else {
      total_time += que.front().second;
      cout << que.front().first << " " << total_time << endl;
      que.pop();
    }
  }

  return EXIT_SUCCESS;
}
