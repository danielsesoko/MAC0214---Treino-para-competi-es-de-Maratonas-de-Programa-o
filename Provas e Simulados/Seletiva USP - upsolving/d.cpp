#include<bits/stdc++.h>
using namespace std;
#define int long long

set<int> s, s_;

void f(int a) {
	a = abs(a);
	for (int i = 1; i * i <= a; i++) if (a % i == 0) {s.insert(i), s.insert(a/i);}	
	s.erase(1);
}

signed main() {
	int n; cin >> n;
	int a[n], dif[n], x[n+1];
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
		if (s_.find(a[i]) == s_.end()) {
			x[s_.size()] = a[i];
			s_.insert(a[i]); 
		} 
	}

	for (int i = 0; i < n; i++) dif[i] = abs(a[i] - a[0]);

	int mdc = 0;
	for (int i = 0; i < n; i++) mdc = __gcd(mdc, dif[i]);
	
	if (mdc == 0) {cout << "1 " << (int)1e9-1 << '\n'; return 0;}

	else if (mdc == 1) {
		if (s_.size() == 2) {cout << "2 " << (int)1e9-1 << '\n'; return 0;}

		f(x[0]-x[1]), f(x[1]-x[2]), f(x[2]-x[0]);
		
		int resp = 0;	
		for (auto d: s) {
			bool flag = true;	
			int resto1 = -1, resto2 = -1;
			for (int i = 0; i < n; i++) {
				if (a[i] % d == resto1 or a[i] % d == resto2) continue;
				else if (resto1 == -1) resto1 = a[i] % d;
				else if (resto2 == -1) resto2 = a[i] % d;
				else flag = false;	
			}
			if (flag) resp++;
		}
		cout << "2 " << resp << '\n'; return 0;
	}

	else {
		f(x[0] - x[1]);
		int resp = 0;	
		for (auto d: s) {
			bool flag = true;	
			for (int i = 0; i < n; i++) if (dif[i] % d != 0) flag = 0;		
			if (flag) resp++;
		}
		cout << "1 " << resp << '\n'; return 0;
	}
}
