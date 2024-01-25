//
// Created by 박기현 on 2024/01/25.
//
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        string line;
        getline(cin, line);
        if (line == ".") break;

        stack<char> s;
        bool error = false;
        for (auto c: line) {
            if (c == '(' || c == '[') s.push(c);
            else if (c == ')') {
                if (s.empty() || s.top() != '(') {
                    error = true;
                    break;
                }
                s.pop();
            } else if (c == ']') {
                if (s.empty() || s.top() != '[') {
                    error = true;
                    break;
                }
                s.pop();
            }
        }

        if (!s.empty()) error = true;
        if (error) cout << "no\n";
        else cout << "yes\n";
    }
    return 0;
}