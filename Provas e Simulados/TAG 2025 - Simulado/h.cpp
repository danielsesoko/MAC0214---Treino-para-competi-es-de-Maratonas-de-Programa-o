#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2*(1e5)+10;
	
vector<int> aux;
int n, d[MAXN];
set<int> s;

int isqrt(int a) {
	int r = sqrt(a);
	while ((r+1) * (r+1) <= a) r++;
	while (r * r > a) r--;
	return r;
}

bool is_prime(int a) {
	if (a == 1) return 0;

	for (int i = 2; i*i <= a; i++) { 
		if (a % i == 0) return 0;
	}

	return 1;
}

void solve() {
	int x = 0, y = 0;

	if (d[1] != 1) {
		cout << d[n] << " 1\n ";
		return; 
	}

	if (n == 1){
	       	cout << "*\n";
	       	return; 
	}
	if (n == 2) {
		if (is_prime(d[2])) {
			x = d[2] * d[2];
		       	y = d[2] * d[2];
		}
		else {
			x = d[2];
		       	y = isqrt(d[2]); 
		}

		cout << x << " " << y << '\n';
		return;
	}
	
	int caso = 1;	
	bool flag = 0;
	for (int i = 1; i <= n; i++) {
		if (d[n] % d[i] != 0) caso = 2;
		if (i >= 2 and d[i] != d[i-1] * d[2]) flag = 1;
	}

	if (flag == 0) caso = 2;

	if (caso == 1) {
		x = d[n];
		for (int i = 1; i <= n; i++) {
			if (s.find(x/d[i]) == s.end()) y = x/d[i];
		}
		if (y == 0) y = isqrt(x);
	}
	else {
		x = d[2] * d[n];
		y = x;
	}

	cout << x << " " << y << '\n';
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		aux.emplace_back(t);
		s.insert(t);
	}
	sort(aux.begin(), aux.end());
	for (int i = 1; i <= n; i++) d[i] = aux[i-1];

	solve();
}
