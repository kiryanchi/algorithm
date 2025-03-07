#include <bits/stdc++.h>
using namespace std;

const int MX = 500 * 80 + 5;
const int ROOT = 1;
int unused = 2;
map<string, int> nxt[MX];

void insert(vector<string>& v) {
    int cur = ROOT;

    for (auto s : v) {
        if (nxt[cur][s] == 0) nxt[cur][s] = unused++;
        cur = nxt[cur][s];
    }
}

void dfs(int cur, int depth) {
    for (auto m : nxt[cur]) {
        for (int i = 0; i < depth; i++) cout << ' ';
        cout << m.first << '\n';
        dfs(m.second, depth+1);
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        vector<string> v;
        string cur = "";
        for (auto c : s) {
            if (c == '\\') {
                v.push_back(cur);
                cur = "";
            } else cur += c;
        }
        v.push_back(cur);
        insert(v);
    }

    dfs(ROOT, 0);

    return 0;
}