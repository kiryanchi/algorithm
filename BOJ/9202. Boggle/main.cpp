#include <bits/stdc++.h>
using namespace std;

// Trie
const int MX = 300000 * 8 + 5;
const int ROOT = 1;
int unused = 2;
int nxt[MX][26];
bool chk[MX];

// Board
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
char board[4][4];
bool vis[4][4];
set<string> found;
int dp[4][4][8];

int c2i(char c) {
    return c - 'A';
}

void insert(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c] == -1) nxt[cur][c] = unused++;
        cur = nxt[cur][c];
    }
    chk[cur] = true;
}

bool find(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c] == -1) return false;
        cur = nxt[cur][c];
    }
    return chk[cur];
}

void dfs(int x, int y, int cur, string word) {
    if (cur == 9) return;

    if (find(word)) {
        // cout << word << '\n';
        found.insert(word);
    }
    vis[x][y] = true;

    // 현재 위치 기준 8방위 탐색해서 다음 글자가 있으면 dfs
    for (int dir = 0; dir < 8; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        char c = board[nx][ny];

        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
        if (vis[nx][ny]) continue;
        if (nxt[cur][c] == 0) continue;

        dfs(nx, ny, cur+1, word + c);
    }
    vis[x][y] = false;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    for (int i = 0; i < MX; i++) fill(nxt[i], nxt[i]+26, -1);
    int w; cin >> w;
    while (w--) {
        string word; cin >> word;
        insert(word);
    }

    int b; cin >> b;
    while (b--) {
        found.clear();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 8; k++) {
                    dp[i][j][k] = 0;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            string line; cin >> line;
            for (int j = 0; j < 4; j++) {
                board[i][j] = line[j];
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                char c = board[i][j];
                // trie에 없으면 스킵
                if (nxt[ROOT][c] == -1) continue;

                // cout << "x, y: " << i << ' ' << j << '\n';
                dfs(i, j, ROOT, string("") + board[i][j]);
            }
        }

        int score = 0;
        string answer = "";
        for (auto s : found) {
            switch (s.size()) {
                case 3: score += 1; break;
                case 4: score += 1; break;
                case 5: score += 2; break;
                case 6: score += 3; break;
                case 7: score += 5; break;
                case 8: score += 11; break;
            }
            if (answer.length() < s.length()) answer = s;
            else if (answer.length() == s.length()) answer = min(answer, s);
        }

        cout << score << ' ' << answer << ' ' << found.size() << '\n';
    }

    return 0;
}