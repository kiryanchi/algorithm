//
// Created by kirya on 2024-02-05.
//
#include <bits/stdc++.h>
using namespace std;

string board[102];
int dist[102][102];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> board[i];
        fill(dist[i], dist[i] + m, -1);
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;

            q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }

    cout << dist[n-1][m-1];

    return 0;
}