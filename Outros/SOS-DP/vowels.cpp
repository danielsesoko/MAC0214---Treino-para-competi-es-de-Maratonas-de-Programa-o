#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

void solve();

signed main() {
	fastio();
	solve();
}

const int MAX = (1<<24) - 1;

vector<int> A(MAX+10);
vector<int> dp0(MAX+10), dp1(MAX+10);

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		string word;
		cin >> word;
		int mask = 0;
		for (auto c: word) {
			int bit = c - 'a';
			if (mask & (1<<bit)) continue;
			mask |= (1<<bit);
		}	
		A[mask]++;
	}
	
	for (int x = 0; x <= MAX; x++) {
		dp0[x] = A[x];
	}
	
	for (int i = 1; i <= 24; i++) {
		for (int x = 0; x <= MAX; x++) {
			dp1[x] = dp0[x];
			if (x & (1<<(i-1))) {
				dp1[x] += dp0[x - (1<<(i-1))];
			}	
		}
		dp0 = dp1;
	}
	
	ll resp = 0;	
	for (int x = 0; x <= MAX; x++) {
		ll temp = (n - dp1[x]) * (n - dp1[x]);		
		resp ^= temp;
	}
	
	cout << resp << '\n';
}
