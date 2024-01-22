//
// Created by 박기현 on 2024/01/22.
//
#include <bits/stdc++.h>
using namespace std;

int T;

deque<int> string_to_deque(string& s) {
    deque<int> d;

    int num = 0;
    for (auto& c : s) {
        if (c - '0' >= 0 && c - '0' <= 9) {
            num *= 10;
            num += c - '0';
        } else if (c == ',' || c == ']') {
            if (num) d.push_back(num);
            num = 0;
        }
    }

    return d;
}

void solve(string& p, string& s) {
    deque<int> d = string_to_deque(s);

    bool is_reverse = false;
    for (auto& op : p) {
        if (op == 'R') {
            is_reverse = !is_reverse;
        } else if (op == 'D') {
            if (d.empty()) {
                cout << "error" << '\n';
                return;
            } else {
                if (is_reverse) d.pop_back();
                else d.pop_front();
            }
        }
    }

    if (d.empty()) cout << "[]\n";
    else {
        if (is_reverse) reverse(d.begin(), d.end());
        cout << '[';
        for (int i = 0; i < d.size() - 1; i++) {
            cout << d[i] << ',';
        }
        cout << d[d.size() - 1] << ']' << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--) {
        string p, s;
        int n;
        cin >> p >> n >> s;

        solve(p, s);
    }
    return 0;
}
