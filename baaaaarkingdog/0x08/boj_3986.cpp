//
// Created by 박기현 on 2024/01/25.
//
#include <bits/stdc++.h>
using namespace std;

int N, cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--) {
        string line;
        cin >> line;

        stack<char> s;
        for (auto& c: line) {
            if (s.empty() || s.top() != c) {
                s.push(c);
            } else if (s.top() == c) {
                s.pop();
            }
        }

        if (s.empty()) cnt++;
    }

    cout << cnt;
    return 0;
}