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

int dist[10050];
vector<pii> edges[10050];   // ex) N = 5, M = 2 => (3, 1) = 7

bool inBound(int x, int y) {
    return 0<x && x<=N && 0<y && y<=M;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    cin >> M >> N; // 가로 M, 세로 N

    fill (dist, dist+10050, INF);   // 거리를 모두 INF

    for (int x = 1; x <= N; x++) {
        string line; cin >> line;
        for (int y = 1; y <= M; y++) {
            board[x][y] = line.at(y-1) - '0';
        }
    }

    // (1,1) 부터 (N, M)까지 상하좌우를 확인하며 갈 수 있다면 그 곳의 값을 비용으로 추가한다.
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= M; y++) {
            int V = (x-1)*M + y;

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (!inBound(nx, ny)) continue;

                edges[V].push_back({ board[nx][ny], (nx-1)*M + ny });
            }
        }
    }

    // 1,1 부터 N,M 까지 최소 비용을 게산하면 그것이 정답
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[1] = 0;
    pq.push({ dist[1], 1 });

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if (dist[cur.Y] != cur.X) continue;
        for (auto nxt : edges[cur.Y]) {
            if (dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;

            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({ dist[nxt.Y], nxt.Y });
        }
    }

    cout << dist[(N-1)*M + M];

    return 0;
}