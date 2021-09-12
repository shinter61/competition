#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> s(3);
    vector<int> p(26, -1);
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
        for (auto elm : s[i]) {
            if (p[elm - 'a'] == -1) {
				p[elm - 'a'] = cnt++;
			}
		}
    }
    if (cnt > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }
    vector<int> num(10);
    iota(num.begin(), num.end(), 0);
    do {
        bool flg = false;
        vector<int64_t> ans(3, 0);
        for (int i = 0; i < 3; i++) {
            for (auto elm : s[i]) {
                ans[i] = ans[i] * 10 + num[p[elm - 'a']];
                if (ans[i] == 0) flg = true;
            }
        }
        if (flg) continue;
        if (ans[0] + ans[1] == ans[2]) {
            for (auto elm : ans) {
				cout << elm << endl;
			}
            return 0;
        }
    } while (next_permutation(num.begin(), num.end()));

    cout << "UNSOLVABLE" << endl;
    return 0;
}
