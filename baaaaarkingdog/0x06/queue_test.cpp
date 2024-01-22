//
// Created by 박기현 on 2024/01/22.
//
#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;
int dat[MX];
int head = 0, tail = 0;

void push(int x) {
    dat[tail++] = x;
}

void pop() {
    head++;
}

int front() {
    return dat[head];
}

int back() {
    return dat[tail-1];
}

void test() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}
