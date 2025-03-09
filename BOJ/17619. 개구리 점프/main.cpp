#include <bits/stdc++.h>
using namespace std;

int p[200002];
pair<int, int> t[100002];

void init() {
    // 통나무 개수는 N개지만, 수의 범위는 0부터 10^9
    fill(p, p+200002, -1);
}

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void uni(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return;
    if (p[v] < p[u]) swap(v, u);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return;
}

bool check(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    int N, Q; cin >> N >> Q;
    init();

    vector<int> uniq;
    for (int i = 1; i <= N; i++) {
        int x1, x2, y; cin >> x1 >> x2 >> y;
        t[i] = {x1, x2};
        uniq.push_back(x1); uniq.push_back(x2);
    }

    sort(uniq.begin(), uniq.end());
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());

    for (int i = 1; i <= N; i++) {
        int nx1 = lower_bound(uniq.begin(), uniq.end(), t[i].first) - uniq.begin();
        int nx2 = lower_bound(uniq.begin(), uniq.end(), t[i].second) - uniq.begin();

        t[i] = {nx1, nx2};

        for (int j = nx1; j < nx2; j++) {
            uni(j, nx2);
        }
    }

    while (Q--) {
        int n1, n2; cin >> n1 >> n2;
        cout << check(t[n1].first, t[n2].first) << '\n';
    }

    return 0;
}