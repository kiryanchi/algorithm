#include <iostream>
#include <string>
#include <map>
using namespace std;

const int MX = 1000 * 15 + 5;
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

void dfs(int cur, int d) {
    for (auto nx : nxt[cur]) {
        for (int i = 0; i < d; i++) cout << "--";
        cout << nx.first << '\n';
        dfs(nx.second, d+1);
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int K; cin >> K;
        vector<string> v(K);
        for (int j = 0; j < K; j++) {
            string s; cin >> s;
            v[j] = s;
        }
        insert(v);
    }

    dfs(ROOT, 0);

    return 0;
}