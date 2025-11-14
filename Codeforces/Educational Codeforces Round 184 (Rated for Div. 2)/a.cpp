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
	int n, a; cin >> n >> a;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	int menor = 0, maior = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] < a) menor++;
	       	else if (v[i] > a) maior++;	
	}
	
	if (menor > maior) cout << a-1 << endl;
	else cout << a+1 << endl;
}
