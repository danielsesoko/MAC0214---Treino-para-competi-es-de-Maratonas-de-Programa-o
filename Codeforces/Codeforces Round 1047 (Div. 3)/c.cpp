#include<bits/stdc++.h>
using namespace std;

#define int long long

int solve() {
	int a, b; cin >> a >> b;

	if (a%2 == 0 and b%2 == 1) return -1;

	if (a%2 == 1 and b%2 == 1) return a * b + 1;

	if (a%2 == 1 and b%2 == 0) {
		if (b%4 != 0) return -1;
		if (a == 1) return 2 + b/2;
		return a * b/2 + 2;
	}

	return a * b/2 + 2;
}

signed main(){
	int t; cin >> t;
	while(t--) {
		cout << solve() << '\n';
	}
}
