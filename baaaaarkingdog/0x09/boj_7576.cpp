//
// Created by kirya on 2024-02-05.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
int warehouse[1001][1001];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> warehouse[i][j];
            if (warehouse[i][j] == 1) q.push({i, j});
        }
    }

    while(!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (warehouse[nx][ny] == -1) continue;
            if (warehouse[nx][ny] != 0 && warehouse[nx][ny] <= warehouse[cur.first][cur.second] + 1) continue;

            q.push({nx, ny});
            warehouse[nx][ny] = warehouse[cur.first][cur.second] + 1;
        }
    }

    int tmp = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (warehouse[i][j] == 0) {
                cout << -1;
                return 0;
            }
            if (tmp < warehouse[i][j]) tmp = warehouse[i][j];
        }
    }

    cout << tmp - 1;

    return 0;
}