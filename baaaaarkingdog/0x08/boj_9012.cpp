//
// Created by 박기현 on 2024/01/25.
//
#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--) {
        string ps;
        cin >> ps;

        stack<char> s;
        bool error = false;
        for (auto& p: ps) {
            if (p == '(') s.push(p);
            else {
                if (s.empty()) {
                    error = true;
                    break;
                }
                s.pop();
            }
        }

        if (!s.empty()) error = true;
        if (error) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}