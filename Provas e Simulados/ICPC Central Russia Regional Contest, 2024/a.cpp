#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

void solve();

signed main() {
	fastio();
	solve();
}

void solve() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];	
	}
	
	int i = 0;
	int cnt0 = 0, cnt1 = 0;
	if (a[0] < a[1]) {
		while (a[i] < a[i+1] and i < n-1) {
			i++;
			cnt0++;
		}
		
		while (a[i] > a[i+1] and i < n-1) {
			i++;
			cnt1++;
		}
	}
	else {
		while (a[i] > a[i+1] and i < n-1) {
			i++;
			cnt0++;
		}

		while (a[i] < a[i+1] and i < n-1) {
			i++;
			cnt1++;
		}

	}

	if (cnt0 + cnt1 == n - 1 and cnt0 > 0 and cnt1 > 0) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}
