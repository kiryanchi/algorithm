#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MX = 500 * 80 + 5;
const int ROOT = 1;
int unused = 2;
unordered_map<string, int> nxt[MX];
int depth[MX];
string name[MX];

void insert(vector<string>& route) {
    int v = ROOT;

    for (auto r : route) {
        int nv = nxt[v][r];
        // 경로가 없으면
        if (nv == 0) {
            nxt[v][r] = unused++;
            nv = nxt[v][r];
        }
        depth[nv] = depth[v] + 1;
        name[nv] = r;
        v = nxt[v][r];
    }
}

void dfs(int v) {
    if (v != ROOT) {
        for (int i = 0; i < depth[v]; i++) cout << ' ';
        cout << name[v] << '\n';
    }

    vector<pair<string, int>> m(nxt[v].begin(), nxt[v].end());
    sort(m.begin(), m.end());
    for (auto mm : m) dfs(mm.second);
}

int N;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    cin >> N;
    depth[ROOT] = -1;

    while (N--) {
        string input; cin >> input;

        vector<string> route;
        string s = "";
        for (auto c : input) {
            if (c == '\\') {
                route.push_back(s);
                s = "";
            } else s += c;
        }
        route.push_back(s);
        insert(route);
    }

    dfs(ROOT);

    return 0;
}