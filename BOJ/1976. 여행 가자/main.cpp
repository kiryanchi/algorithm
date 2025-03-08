#include <bits/stdc++.h>
using namespace std;

int N, M;
bool trip[205];
bool vis[205];
vector<int> adj[205];

void dfs(int cur) {
    vis[cur] = true;

    for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    cin >> N >> M;;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)  {
            int n; cin >> n;
            if (n == 1) {
                adj[i].push_back(j);
            }
        }
    }

    int city; 
    for (int i = 0; i < M; i++) {
        cin >> city;
        trip[city] = 1;
    }

    dfs(city);

    for (int i = 0; i < N; i++) {
        if (!trip[i]) continue;

        if (!vis[i]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}