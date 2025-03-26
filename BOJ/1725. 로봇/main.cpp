#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

#define endl '\n'
#define first X
#define second Y

int dx[] = { 0, 0, 0, 1, -1 };
int dy[] = { 0, 1, -1, 0, 0 };

int M, N;
int board[102][102];
int stX, stY, stD;
int edX, edY, edD;

int vis[102][102][5];

int rotationRight(int dir) {
	if (dir == 1) return 3;
	if (dir == 2) return 4;
	if (dir == 3) return 2;
	if (dir == 4) return 1;

	return -1;
}

int rotationLeft(int dir) {
	if (dir == 1) return 4;
	if (dir == 2) return 3;
	if (dir == 3) return 1;
	if (dir == 4) return 2;

	return -1;
}

// left == 1
int rotation(int dir, int left) {
	if (left) return rotationLeft(dir);
	return rotationRight(dir);
}

bool inBound(int x, int y) {
	return 0 < x && x <= M && 0 < y && y <= N;
}

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);

	cin >> M >> N;
	for (int x = 1; x <= M; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> board[x][y];
		}
	}

	// 현재 좌표와 방향 입력, 방향은 0-indexed
	cin >> stX >> stY >> stD;

	// 목표 좌표와 방향 입력, 방향은 0-indexed
	cin >> edX >> edY >> edD;

	queue<tuple<int, int, int>> q;

	// 현재 좌표와 바라보는 방향
	vis[stX][stY][stD] = 1;
	q.push({ stX, stY, stD });

	int ans = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int x, y, d;
		tie(x, y, d) = cur;

		// 목표 좌표와 방향이 됐다면 종료
		if (x == edX && y == edY && d == edD) {
			ans = vis[x][y][d] - 1;
			break;
		}

		// 현재 좌표에서 왼쪽 오른쪽으로 회전
		for (int left = 0; left < 2; left++) {
			int nd = rotation(d, left);
			if (vis[x][y][nd] != 0 && vis[x][y][nd] <= vis[x][y][d] + 1) continue;

			vis[x][y][nd] = vis[x][y][d] + 1;
			q.push({ x, y, nd });
		}

		// 현재 바라보는 방향으로 1~ 3칸 이동
		for (int dis = 1; dis <= 3; dis++) {
			int nx = x + dx[d] * dis;
			int ny = y + dy[d] * dis;

			
			if (!inBound(nx, ny) || board[nx][ny] == 1) break;
			if (vis[nx][ny][d] != 0 && vis[nx][ny][d] <= vis[x][y][d] + 1) continue;

			vis[nx][ny][d] = vis[x][y][d] + 1;
			q.push({ nx, ny, d });
		}
	}
	cout << ans;

	return 0;
}
