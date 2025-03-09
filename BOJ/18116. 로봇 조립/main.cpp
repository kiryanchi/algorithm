#include <bits/stdc++.h>
using namespace std;

int N;
int p[1000002];
int cnt[1000002];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);

    // 같은 집합이라면 종료
    if (u == v) {
        return 0;
    }

    // 다른 집합이라면 개수를 옮겨준다.
    if (p[v] < p[u]) swap(v, u);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    cnt[u] += cnt[v];
    cnt[v] = 0;
    return 1;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    cin >> N;
    // a와 b의 값이 10^6 이므로 ...
    // n 까지 초기화하는 것이 아니다...
    // 문제를 잘 읽자..
    for (int i = 0; i < 1000002; i++) {
        p[i] = -1;
        cnt[i] = 1;
    }

    while (N--) {
        char cmd; cin >> cmd;
        if (cmd == 'I') {
            int a, b; cin >> a >> b;
            uni(a, b);
        } else {
            int a; cin >> a;
            int par = find(a);
            cout << cnt[par] << '\n';
        }
    }

    return 0;
}