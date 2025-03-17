#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

struct info {
	int group;
	int level;
};

string op;
int N, P, L, G, x;

unordered_map<int, info> infos;
unordered_map<int, map<int, set<int>>> db;

void insert_db(int p, int l, int g) {
	infos[p] = {g, l};

	if (db.find(g) == db.end()) db.insert({ g, map<int, set<int>>() });
	if (db[g].find(l) == db[g].end()) db[g].insert({ l, set<int>() });
	db[g][l].insert(p);

	if (db.find(0) == db.end()) db.insert({ 0, map<int, set<int>>() });
	if (db[0].find(l) == db[0].end()) db[0].insert({ l, set<int>() });
	db[0][l].insert(p);
}

int main () {
	cin.tie(0)->ios::sync_with_stdio(0);

	cin >> N;
	while (N--) {
		cin >> P >> L >> G;
		insert_db(P, L, G);
	}

	cin >> N;
	while (N--) {
		cin >> op;
		if (op == "add") {
			cin >> P >> L >> G;
			insert_db(P, L, G);
			continue;
		}

		if (op == "solved") {
			cin >> P;
			info& i = infos[P];
			G = i.group;
			L = i.level;
			db[G][L].erase(P);
			if (db[G][L].size() == 0) db[G].erase(L);
			db[0][L].erase(P);
			if (db[0][L].size() == 0) db[0].erase(L);
			infos.erase(P);
			continue;
		}

		if (op == "recommend") {
			cin >> G >> x;
			if (x == 1) {
				cout << *(db[G].rbegin()->second.rbegin()) << endl;
				continue;
			}

			if (x == -1) {
				cout << *(db[G].begin()->second.begin()) << endl;
				continue;
			}
		}

		if (op == "recommend2") {
			cin >> x;
			if (x == 1) {
				cout << *(db[0].rbegin()->second.rbegin()) << endl;
				continue;
			}

			if (x == -1) {
				cout << *(db[0].begin()->second.begin()) << endl;
				continue;
			}
		}

		if (op == "recommend3") {
			cin >> x >> L;

			// 문제가 하나도 없는 경우 불가능
			if (infos.size() == 0) {
				cout << -1 << endl;
				continue;
			}

			// L이 있다면 L을 반환
			// L이 없다면 L다음 값을 반환 ({10, 15} -> 11 검색 -> 15)
			auto it = db[0].lower_bound(L);
			if (x == 1) {
				if (it == db[0].end()) {
					cout << -1 << endl;
					continue;
				}

				if (it->second.empty()) {
					cout << -1 << endl;
					continue;
				}

				cout << *(it->second.begin()) << endl;
				continue;
			}

			if (x == -1) {
				if (it == db[0].begin() && it->first >= L) {
					cout << -1 << endl;
					continue;
				}

				if (it->second.empty()) {
					cout << -1 << endl;
					continue;
				}

				it = prev(it);
				cout << *(it->second.rbegin()) << endl;
				continue;
			}
		}
	}
}