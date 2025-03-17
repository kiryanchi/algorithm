#include <iostream>
using namespace std;

int N;

// {h, w, d, e, l, o, r}
int sel[7];
int ans[7];
bool use[10];
bool flag;

void solve(int cnt) {
	if (flag) return;
	if (cnt == 7) {
		for (int i = 0; i < 7; i++) {
			int h = sel[0];
			int w = sel[1];
			int d = sel[2];
			int e = sel[3];
			int l = sel[4];
			int o = sel[5];
			int r = sel[6];
			
			int sum = ((10000 * h + 1000 * e + 100 * l + 10 * l + o) + (10000 * w + 1000 * o + 100 * r + 10 * l + d));
			if (sum == N) {
				flag = true;
				for (int j = 0; j < 7; j++) {
					ans[j] = sel[j];
				}
			}
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		// h와 w는 0에서 제외한다.
		if ((cnt == 0 || cnt == 1) && i == 0) continue;
		if (use[i]) continue;
		sel[cnt] = i;

		use[i] = true;
		solve(cnt + 1);
		use[i] = false;
	}
}

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);

	cin >> N;

	solve(0);

	if (!flag) cout << "No Answer";
	else {
		int h = ans[0];
		int w = ans[1];
		int d = ans[2];
		int e = ans[3];
		int l = ans[4];
		int o = ans[5];
		int r = ans[6];
		cout << "  " << h << e << l << l << o << '\n';
		cout << "+ " << w << o << r << l << d << '\n';
		cout << "-------\n";
		if (N < 100000) cout << "  " << N;
		else cout << " " << N;
	}

	return 0;
}