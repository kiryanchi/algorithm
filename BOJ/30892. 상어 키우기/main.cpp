#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

using ll = long long;

ll N, K, T;
ll arr[200002];

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);

	cin >> N >> K >> T;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	stack<ll> pq;

	int idx = 0;
	while (idx < N && arr[idx] < T) pq.push(arr[idx++]);

	for (int i = 0; i < K; i++) {
		if (pq.empty() || pq.top() >= T) break;

		T += pq.top(); pq.pop();

		while (idx < N && arr[idx] < T) pq.push(arr[idx++]);
	}

	cout << T;

	return 0;
}
