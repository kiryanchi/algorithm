#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll T[100002];
ll ans;

bool check(ll c) {
	ll cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt += c / T[i];
		if (cnt >= M) return true;
	}
	return false;
}

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);

	cin >> N >> M;

	ll mx = 0;
	for (int i = 0; i < N; i++) {
		cin >> T[i];
		mx = max(mx, T[i]);
	}

	mx = mx * M;
	ll l = 1, r = mx, c;

	while (l < r) {
		c = (l + r) / 2;

		if (check(c)) r = c;
		else l = c+1;
	}

	cout << l;
	return 0;
}