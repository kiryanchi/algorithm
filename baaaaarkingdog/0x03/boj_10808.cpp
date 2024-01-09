//
// Created by 박기현 on 2024/01/10.
// 문제 - https://acmicpc.net/problem/10808
//
#include <bits/stdc++.h>
using namespace std;

int alphabet[26] = {0, };
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    for (char& c : input) {
        alphabet[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << ' ';
    }
    return 0;
}