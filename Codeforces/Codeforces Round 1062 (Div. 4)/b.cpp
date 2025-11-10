#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

void solve();

signed main() {
	fastio();
	int q; cin >> q;
	while (q--) solve();
}

void solve() {
	int n; cin >> n;
	string a, b; cin >> a >> b;
	vector<int> freq(26, 0);	

	for (auto c: a) freq[c - 'a']++;
	for (auto c: b) freq[c - 'a']--;
	
	bool flag = true;
	for (int i = 0; i < 26; i++) {
		if (freq[i] != 0) flag = false;
	}	

	if (flag) cout << "YES\n";
	else cout << "NO\n";
}
