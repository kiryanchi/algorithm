//
// Created by 박기현 on 2024/01/25.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string ps;
    cin >> ps;

    stack<char> s;
    int cnt = 0, close_cnt = 0;
    bool is_open = false;
    for (auto& p: ps) {
        if (p == '(') {
            s.push(p);
            is_open = true;
            if (close_cnt) {
                cnt += close_cnt;
                close_cnt = 0;
            }
        }
        else {
            s.pop();
            if (is_open) {
                cnt += s.size();
                is_open = false;
            } else {
                close_cnt++;
            }
        }
    }

    cout << cnt + close_cnt;

    return 0;
}