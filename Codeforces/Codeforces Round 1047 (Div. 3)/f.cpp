#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 2 * (1e5+10);

vector<int> a(MAX+1, 0), b(MAX+1, 0);
int seg[4*MAX];
int n;

int build(int p=1, int l=1, int r=n) {
	if (l == r) return seg[p] = a[l];
	int m = (l+r)/2;
	return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
}

int query(int a, int b, int p=1, int l=1, int r=n) {
	if (a <= l and r <= b) return seg[p];
	if (b < l or r < a) return 0;
	int m = (l+r)/2;
	return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
}

int get_right(int a, int b, int val, int p=1, int l=1, int r=n) {
	if (b < l or r < a or seg[p] < val) return -1;
	if (r == l) return l;
	int m = (l+r)/2;
	int x = get_right(a, b, val, 2*p+1, m+1, r);
	if (x != -1) return x;
	return get_right(a, b, val, 2*p, l, m);
}

void solve() {
	cin >> n;
	
	vector<bool> aloc(n+1, 0);

	int amaxi = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > amaxi) aloc[i] = 1;
		amaxi = max(a[i], amaxi);
	}

	build();

	int total = 0, soma = 0;
	for (int i = 1; i <= n; i++) {
		total += (i * (n-i+1));

		int b; cin >> b;
		if (a[i] == b) continue;
		if (a[i] > b) {
			if (aloc[i] == 1) soma += (i * (n-i+1));
			else {
				int j = get_right(1, i-1, a[i]);
				soma += (max(i - j, 1LL) * (n - i + 1));
			}
			continue;
		}
		else {
			int j = get_right(1, i-1, b);
			if (j == -1) soma += (i * (n - i + 1));
			else soma += ((i - j) * (n - i + 1));
		}
	}
	cout << total - soma << '\n';
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
}
