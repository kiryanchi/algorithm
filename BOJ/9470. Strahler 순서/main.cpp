#include <bits/stdc++.h>
using namespace std;

int T, K, M, P, mx;
int par[1002], ans[1002];
vector<int> dn[1002], up[1002];

void init() {
    mx = 0;
    for (int i = 0; i <= M; i++) {
        ans[i] = 0;
        par[i] = 0;
        dn[i].clear();
        up[i].clear();
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> K >> M >> P;
        init();

        for (int i = 0; i < P; i++) {
            int A, B; cin >> A >> B;
            dn[A].push_back(B);
            up[B].push_back(A);
            par[B]++;
        }

        queue<int> q;
        for (int i = 1; i <= M; i++) {
            if (par[i] == 0) {
                q.push(i);
                ans[i] = 1;
            }
        }

        while (!q.empty()) {
            int cur = q.front(); q.pop();

            for (auto nxt : dn[cur]) {
                if (--par[nxt] == 0) {
                    q.push(nxt);

                    int mx1 = 0, mx2 = 0;
                    for (auto prev : up[nxt]) {
                        if (mx1 == mx2) {
                            if (ans[prev] > mx1) mx1 = ans[prev];
                        } else if (mx1 > mx2) {
                            if (ans[prev] > mx1) mx1 = ans[prev];
                            else mx2 = ans[prev];
                        }
                    }

                    if (mx1 == mx2) ans[nxt] = mx1+1;
                    else ans[nxt] = mx1;

                    mx = max(mx, ans[nxt]);
                }
            }
        }

        cout << K << ' ' << mx << '\n';
    }

    return 0;
}