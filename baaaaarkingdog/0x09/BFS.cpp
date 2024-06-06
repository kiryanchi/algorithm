//
// Created by 박기현 on 2024/01/30.
//
#include <bits/stdc++.h>
using namespace std;

int board[502][502] = {{1,1,1,0,1,0,0,0,0,0},
                       {1,0,0,0,1,0,0,0,0,0},
                       {1,1,1,0,1,0,0,0,0,0},
                       {1,1,0,0,1,0,0,0,0,0},
                       {0,1,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0}};
bool vis[502][502];
int n = 7, m = 10;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;
    vis[0][0] = 1;

    Q.push({0, 0});
    while (!Q.empty()) {
        pair<int, int> pos = Q.front(); Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (vis[nx][ny] || board[nx][ny] != 1) continue;

            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }

    return 0;
}