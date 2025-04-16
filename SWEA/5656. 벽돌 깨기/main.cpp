#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int N, W, H;
int board[15][20];
int tmp[15][20];
bool deleted[15][20];

int ans;
int sel[15];
bool use[15];

void print() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << tmp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool inBound(int x, int y) {
    return 0<=x&&x<H && 0<=y&&y<W;
}

void boom(int x, int y) {
    deleted[x][y] = 1;

    // 숫자에 적힌 칸 - 1 만큼 터진다.
    int size = tmp[x][y] - 1;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x;
        int ny = y;

        for (int i = 0; i < size; i++) {
            nx += dx[dir];
            ny += dy[dir];

            // 맵의 범위를 벗어나는 경우, 칸이 0인 경우, 이미 삭제된 경우
            if (!inBound(nx, ny) || tmp[nx][ny] == 0 || deleted[nx][ny]) continue;

            boom(nx, ny);
        }
    }
}

void shoot(int targetY) {
    // 터질 블록들을 저장할 bool 배열
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            deleted[x][y] = 0;
        }
    }

    // 현재 x 좌표
    int targetX = 0;

    // 처음 블록을 만날 때까지 x를 증가시킴
    while (targetX < H && tmp[targetX][targetY] == 0) {
        targetX++;
    }

    // 블록을 만나지 못 하고 끝에 도달했으니 종료
    if (targetX == H) {
        return;
    }

    // 블록이 터지는 위치를 DFS로 선택
    boom(targetX, targetY);

    // 실제로 블록이 사라짐
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            if (deleted[x][y]) {
                tmp[x][y] = 0;
            }
        }
    }
}

void fall() {
    for (int y = 0; y < W; y++) {
        // 블록은 아래로 떨어져야 함
        for (int x = H-1; x > 0; x--) {
            // x,y 에 블록이 있을 경우 패스
            if (tmp[x][y] == 0) {
                int nx = x-1;
                // x 좌표 위로 블록을 찾음
                while (nx >= 0 && tmp[nx][y] == 0) {
                    nx--;
                }

                // 만약 위로 다 블록이 없다면 그 칸에는 더이상 블록이 없음
                if (nx == -1) continue;

                // 블록을 발견함
                tmp[x][y] = tmp[nx][y];
                tmp[nx][y] = 0;
            }
        }
    }
}

int simulation() {
    // 보드를 복사
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            tmp[x][y] = board[x][y];
        }
    }
    
    // 선택된 좌표들로 공을 발사
    for (int i = 0; i < N; i++) {
        int y = sel[i];
        
        // 공을 발사
        shoot(y);
        
        // 아래로 공을 당김
        fall();
    }
    
    // 남은 공을 셈
    int cnt = 0;
    for (int x = 0 ; x < H; x++) {
        for (int y = 0; y < W; y++) {
            if (tmp[x][y] > 0) cnt++;
        }
    }

    return cnt;
}

void solve(int cnt) {
    if (cnt == N) {
        ans = min(ans, simulation());
        return;
    }

    for (int y = 0; y < W; y++) {
        if (use[y]) continue;

        // y좌표에 공을 쏘기로 선택
        sel[cnt] = y;
        solve(cnt+1);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0)->ios::sync_with_stdio(0);

    int TC; cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        // 구슬의 개수, 가로 W, 세로 H
        cin >> N >> W >> H;

        // 맵 입력 받음
        for (int x = 0; x < H; x++) {
            for (int y = 0; y < W; y++) {
                cin >> board[x][y];
            }
        }

        // 최대한 많은 벽돌을 꺠고 남은 벽돌의 개수를 세야하므로 
        ans = INT_MAX;
        solve(0);

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}