#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int inf = 100000000;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  stack<pair<int, int>> st;
  st.push({inf, 0});
  for (int i = 0; i < N; i++) {
    while(A[i] > st.top().first) st.pop();

    cout << st.top().second << ", ";

    st.push({A[i], i+1});
  }
  return EXIT_SUCCESS;
}
