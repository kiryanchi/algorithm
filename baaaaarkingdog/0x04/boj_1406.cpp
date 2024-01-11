//
// Created by kirya on 2024-01-11.
// 문제 - https://acmicpc.net/problem/1406
//
#include <bits/stdc++.h>
using namespace std;

list<char> editor;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string text;
    int n;
    cin >> text >> n;

    for (auto c : text)
        editor.push_back(c);

    auto cur = editor.end();

    while (n--) {
        char op;
        cin >> op;

        if (op == 'P') {
            char c;
            cin >> c;
            editor.insert(cur, c);
        } else if (op == 'L') {
            if (cur != editor.begin()) cur--;
        } else if (op == 'D') {
            if (cur != editor.end()) cur++;
        } else if (op == 'B') {
            if (cur != editor.begin()) {
                cur--;
                cur = editor.erase(cur);
            }
        }
    }

    for (auto c : editor) cout << c;
    return 0;
}