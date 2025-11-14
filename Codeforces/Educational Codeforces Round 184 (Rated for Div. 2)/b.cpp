#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();
}

void solve() {
	string s; cin >> s;
	bool inf = 0;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == '>' and s[i+1] == '<') inf = 1;
		if (s[i] == '*' and s[i+1] == '*') inf = 1;
		if (s[i] == '>' and s[i+1] == '*') inf = 1;
		if (s[i] == '*' and s[i+1] == '<') inf = 1;
	}

	if (inf) {
		cout << -1 << endl;
		return;
	}
	
	int menor = 0, maior = 0, ast = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '<') menor++;
		else if (s[i] == '>') maior++;
		else ast++;
	}

	cout << max(menor, maior) + ast << endl;
}
