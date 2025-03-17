#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct point {
	int x;
	int y;
	int cnt;
	bool v;
};

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N;
bool board[52][52];
int vis[52][52][2];

bool is_valid(const int& x, const int& y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

bool is_possible(const int& x, const int& y, const bool& isVertical) {
	if (!is_valid(x, y) || board[x][y] == 1) return false;
	if (isVertical) {
		if (!is_valid(x - 1, y) || board[x - 1][y] == 1) return false;
		if (!is_valid(x + 1, y) || board[x + 1][y] == 1) return false;
	}
	else {
		if (!is_valid(x, y - 1) || board[x][y - 1] == 1) return false;
		if (!is_valid(x, y + 1) || board[x][y + 1] == 1) return false;
	}
	return true;
}

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);

	cin >> N;
	int bCnt = 0, eCnt = 0;
	point st, ed;
	for (int i = 0; i < N; i++) {
		string line; cin >> line;
		for (int j = 0; j < N; j++) {
			char& c = line.at(j);

			if (c == '1') {
				board[i][j] = 1;
				continue;
			}
			
			board[i][j] = 0;
			if (c == 'B' && ++bCnt == 2) {
				st = point({ i, j, 0, false });
				if (!is_valid(i, j - 1) || line.at(j-1) != 'B') st.v = true;
				continue;
			}

			if (c == 'E' && ++eCnt == 2) {
				ed = point({ i, j , 0, false });
				if (!is_valid(i, j - 1) || line.at(j-1) != 'E') ed.v = true;
			}
		}
	}

	queue<point> q;
	q.push(st);
	vis[st.x][st.y][st.v] = true;

	while (!q.empty()) {
		point c = q.front(); q.pop();

		if (c.x == ed.x && c.y == ed.y && c.v == ed.v) {
			cout << c.cnt;
			return 0;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = c.x + dx[dir];
			int ny = c.y + dy[dir];

			if (is_possible(nx, ny, c.v) && !vis[nx][ny][c.v]) {
				q.push({ nx, ny, c.cnt + 1, c.v });
				vis[nx][ny][c.v] = true;
			}
		}

		bool flag = false;
		for (int dir = 0; dir < 8; dir++) {
			int nx = c.x + dx[dir];
			int ny = c.y + dy[dir];

			if (!is_valid(nx, ny) && board[nx][ny] != 0) {
				flag = true;
				break;
			}
		}

		if (is_possible(c.x, c.y, !c.v) && !vis[c.x][c.y][!c.v] &&
			is_valid(c.x - 1, c.y - 1) && board[c.x - 1][c.y - 1] == 0 &&
			is_valid(c.x - 1, c.y + 1) && board[c.x - 1][c.y + 1] == 0 &&
			is_valid(c.x + 1, c.y - 1) && board[c.x + 1][c.y - 1] == 0 &&
			is_valid(c.x + 1, c.y + 1) && board[c.x + 1][c.y + 1] == 0) {
			q.push({ c.x, c.y, c.cnt + 1, !c.v });
			vis[c.x][c.y][!c.v] = true;
		}
	}

	cout << 0;
	return 0;
}