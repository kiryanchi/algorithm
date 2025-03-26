#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define X first
#define Y second
using ll = long long;
using pii = pair<ll, ll>;

ll N, E;

ll dist[802];
vector<pii> edges[802];

ll getDistance(ll st, ll ed) {
    fill (dist + 1, dist + N + 1, INF);
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[st] = 0;
    pq.push({ dist[st], st });
    
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
    
        if (dist[cur.Y] != cur.X) continue;
    
        for (auto nxt : edges[cur.Y]) {
            if (dist[nxt.Y] <= cur.X + nxt.X) continue;
    
            dist[nxt.Y] = cur.X + nxt.X;
            pq.push({ dist[nxt.Y], nxt.Y });
        }
    }
    
    return dist[ed];
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    cin >> N >> E;      // 정점 N개 간선 E개
    while (E--) {
        // a번에서 b번으로 c비용
        ll a, b, c; cin >> a >> b >> c;

        // 무방향 그래프이므로 a->b, b->a 모두 추가
        edges[a].push_back({c, b});
        edges[b].push_back({c, a});
    }

    ll v1, v2; cin >> v1 >> v2;

    // case 1. 1 -> v1 -> v2 -> N
    ll res1 = getDistance(1, v1) + getDistance(v1, v2) + getDistance(v2, N);
    ll res2 = getDistance(1, v2) + getDistance(v2, v1) + getDistance(v1, N);

    ll ans = min(res1, res2);

    if (ans >= INF) ans = -1;

    cout << ans;

    return 0;
}