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

    int sum = 0, tmp = 1;
    stack<char> s;
    for (int i = 0; i < ps.length(); i++) {
        char c = ps[i];
        if (c == '(') {
            tmp *= 2;
            s.push(c);
        } else if (c == '[') {
            tmp *= 3;
            s.push(c);
        } else if (c == ')') {
            if (s.empty() || s.top() != '(') {
                cout << 0;
                return 0;
            }
            if (ps[i-1] == '(') sum += tmp;
            tmp /= 2;
            s.pop();
        } else if (c == ']') {
            if (s.empty() || s.top() != '[') {
                cout << 0;
                return 0;
            }
            if (ps[i-1] == '[') sum += tmp;
            tmp /= 3;
            s.pop();
        }
    }

    if (s.empty()) cout << sum;
    else cout << 0;

    return 0;
}