#include <bits/stdc++.h>
using namespace std;

int N, M;
int Q, A[1 << 18], B[1 << 18], C[1 << 18], D[1 << 18];
int Answer = 0;

void dfs(int pos, int dep, vector<int> P) {
	if (pos == N) {
		int sum = 0;
		for (int i = 1; i <= Q; i++) {
			if (P[B[i] - 1] - P[A[i] - 1] == C[i]) sum += D[i];
		}
		Answer = max(Answer, sum);
		return;
	}

	for (int i = dep; i <= M; i++) {
		vector<int>PP = P; PP.push_back(i);
		dfs(pos + 1, i, PP);
	}
}

int main() {
	cin >> N >> M >> Q;
	for (int i = 1; i <= Q; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
  vector<int> a;
	dfs(0, 1, a);
	cout << Answer << endl;
	return 0;
}
