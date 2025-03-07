/**
 * 트라이 연습 문제
 */
#include <iostream>
#include <string>
using namespace std;

const int MX = 10000 * 500 + 5;
const int ROOT = 1;
int unused = 2;
// 소문자로만 이루어져 있음. 따라서 26 (0~25)
int nxt[MX][26];
bool chk[MX];

// 소문자로만 이루어져 있음
int c2i(char c) {
    return c - 'a';
}

void init() {
    for (int i = 0; i < MX; i++) fill(nxt[i], nxt[i]+26, -1);
}

void insert(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1) nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
}

bool find(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1) return false;
        cur = nxt[cur][c2i(c)];
    }
    return chk[cur];
}

void erase(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1) return;
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = false;
}

bool is_prefix(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1) return false;
        cur = nxt[cur][c2i(c)];
    }
    return true;
}

int N, M;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    init();

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        insert(s);
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        string s; cin >> s;
        cnt += is_prefix(s);
    }
    cout << cnt;

    return 0;
}