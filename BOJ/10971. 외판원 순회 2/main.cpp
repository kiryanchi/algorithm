#include <iostream>
#define INF 1e9
using namespace std;

int N, ans = INF;
int sel[20];
int W[20][20];
bool vis[20];

void solve(int cnt) {
    if (cnt == N) {
        // 마지막 도시는 처음 도시로 돌아와야 함
        sel[N] = sel[0];

        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (W[sel[i]][sel[i+1]] == 0) return;
            sum += W[sel[i]][sel[i+1]];
        }

        ans = min(ans, sum);
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        sel[cnt] = i;
        vis[i] = 1;
        solve(cnt + 1);
        vis[i] = 0;
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> W[i][j];
        }
    }

    solve(0);

    cout << ans;

    return 0;
}