#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define int long long
const int INF = 1e16;

void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();
}

void solve() {
	int n; cin >> n;
	vector<int> a(n+1);
	vector<int> s(n+10), melhor(n+10, -INF), id(n+10);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}

	for (int i = n; i >= 1; i--) {
		id[i] = id[i+1];
		melhor[i] = max(i * i + i - s[i], melhor[i+1]);
		if (melhor[i] > melhor[i+1]) id[i] = i;
	}
	
	int resp = 0;
	for (int i = 1; i <= n; i++) {
		resp = max(resp, id[i] * id[i] - i * i + (id[i] + i) - s[id[i]] + s[i-1]);
	}

	cout << resp + s[n] << endl;	
}
