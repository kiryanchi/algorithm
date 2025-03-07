#include <bits/stdc++.h>
using namespace std;

const int MX = 100000 * 10 + 5;
const int ROOT = 1;
int unused = 2;
int nxt[MX][26];
int chk[MX];

int c2i(char c) {
    return c - 'a';
}

void insert(string& s) {
    int cur = ROOT;

    bool flag = true;
    for (auto c : s) {
        if (flag) cout << c;
        if (nxt[cur][c] == -1) {
            nxt[cur][c] = unused++;
            flag = false;
        }
        cur = nxt[cur][c];
    }
    chk[cur]++;
    if (flag && chk[cur] > 1) cout << chk[cur];
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    int N; cin >> N;
    for (int i = 0; i < MX; i++) fill(nxt[i], nxt[i]+26, -1);
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        insert(s);
        cout << '\n';
    }

    return 0;
}