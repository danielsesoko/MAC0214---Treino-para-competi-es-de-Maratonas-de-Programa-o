#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

void solve();

signed main() {
	fastio();
	int t; cin >> t;
	while (t--) solve();	
}

const int INF = 1e9+10;

void solve() {
	int n; cin >> n;
	int mini = +INF, maxi = -INF;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		mini = min(mini, a);
		maxi = max(maxi, a);
	}
	int x; cin >> x;

	if (mini <= x and x <= maxi) cout <<"YES\n";
	else cout << "NO\n";
}
