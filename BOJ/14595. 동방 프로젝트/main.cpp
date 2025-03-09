#include <bits/stdc++.h>
using namespace std;

int p[1000002];

int N, M;

void init() {
    fill(p+1, p+N+1, -1);
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
}

bool same(int u, int v) {
    return find(u) == find(v);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    
    cin >> N >> M;
    init();

    vector<pair<int, int>> v;
    while (M--) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.second == p2.second) return p1.first < p2.first;
        return p1.second > p2.second;
    });

    // 정렬을 오른쪽 방부터 묶어나가기 떄문에 현재 방과 오른쪽방이 연결되어 있으면 무조건 사이는 연결되어 있음
    for (auto p : v) {
        int x = p.first, y = p.second;
        for (int i = x; i < y; i++) {
            if (same(i, y)) break;
            uni(i, y);
        }
    }

    // 아래는 끽해야 백만번이라 시간 복잡도에 영향 X
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (p[i] < 0) cnt++;
    }

    cout << cnt;

    return 0;
}