#include <bits/stdc++.h>
using namespace std;

int N, M;
int p[205];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return false;
    if (p[v] < p[u]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    
    fill(p, p+205, -1);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int n; cin >> n;
            if (n == 1) {
                uni(i, j);
            }
        }
    }

    int cur; cin >> cur;
    int par = find(cur);
    for (int i = 1; i < M; i++) {
        cin >> cur;
        if (find(cur) != par) {
            cout << "NO"; return 0;
        }
    }
    cout << "YES";
    return 0;
}