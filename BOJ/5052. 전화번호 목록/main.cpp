#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MX = 10000 * 10 + 5;
const int RT = 1;
int unused = 2;
int nxt[MX][10];
bool chk[MX];

int c2i(char c) {
    return c - '0';
}

bool insert(string& s) {
    int cur = RT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1) nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
        if (chk[cur]) return false;
    }
    return chk[cur] = true;
}

void init() {
    unused = 2;
    fill(chk, chk+MX, 0);
    for (int i = 0; i < MX; i++) fill(nxt[i], nxt[i]+10, -1);
}

bool cmp(const string& s1, const string& s2) {
    return s1.size() < s2.size();
}

int TC, N;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    cin >> TC;
    for (int tc = 0; tc < TC; tc++) {
        init();
        cin >> N;

        vector<string> numbers;
        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            numbers.push_back(s);
        }
        sort(numbers.begin(), numbers.end(), cmp);

        bool flag = true;
        for (int i = 0; i < numbers.size(); i++) {
            flag = insert(numbers[i]);
            if (!flag) break;
        }
        if (!flag) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}