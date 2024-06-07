#include <bits/stdc++.h>

using namespace std;

int n, k;
int cnt = 1;
int dist[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 100001; i++) dist[i] = -1;

    cin >> n >> k;
    queue<int> q;
    q.push(n);
    dist[n] = 0;

    while (dist[k] == -1) {
        auto cur = q.front(); q.pop();
        for (int next: {cur-1, cur+1, cur*2}) {
            if (next < 0 || next > 100000) continue;
            if (dist[next] != -1) continue;
            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }

    cout << dist[k];

    return 0;
}
