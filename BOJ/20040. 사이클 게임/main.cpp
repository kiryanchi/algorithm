#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[500002];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return 1;
    if (p[v] < p[u]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return 0;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    cin >> n >> m;
    fill(p, p+n, -1);

    int i = 1;
    for (i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if (uni(u, v)) break;
    }

    if (i != m) cout << i+1;
    else cout << 0;

    return 0;
}