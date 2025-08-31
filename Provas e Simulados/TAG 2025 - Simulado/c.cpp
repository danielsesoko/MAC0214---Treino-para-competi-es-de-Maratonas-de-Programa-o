#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6+10;
int indice[MAXN];
int dif[MAXN];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> a;

	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		a.emplace_back(--t);
	}

	reverse(a.begin(), a.end());	
	for (int i = 0; i < n; i++) indice[a[i]] = i;

	for (int i = 0; i < n; i++) {
		dif[(a[i] - indice[a[i]] + n) % n]++;
	}

	int resp = n;
	for (int i = 0; i <= n; i++) {
		resp += (dif[i] * (dif[i]-1));	
	}
	cout << resp << '\n';
}
