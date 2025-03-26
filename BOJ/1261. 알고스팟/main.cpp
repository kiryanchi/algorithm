#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define X first
#define Y second
using pii = pair<int, int>;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int N, M;
int board[102][102];

int d[102][102];

bool inBound(int x, int y) {
    return 0<x && x<=N && 0<y && y<=M;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    cin >> M >> N; // 가로 M, 세로 N

    for (int i = 1; i <= N; i++)
        fill (d[i] + 1, d[i] + 1 + M, INF);   // 거리를 모두 INF

    for (int x = 1; x <= N; x++) {
        string line; cin >> line;
        for (int y = 1; y <= M; y++) {
            board[x][y] = line.at(y-1) - '0';
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    d[1][1] = 0;
    pq.push({ d[1][1], 1, 1 });

    while (!pq.empty()) {
        int cw, cx, cy;
        tie(cw, cx, cy) = pq.top(); pq.pop();
        if (cw != d[cx][cy]) continue;

        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (!inBound(nx, ny)) continue;
            if (d[nx][ny] <= cw + board[nx][ny]) continue;

            d[nx][ny] = cw + board[nx][ny];
            pq.push({ d[nx][ny], nx, ny });
        }
    }
    
    cout << d[N][M];

    return 0;
}