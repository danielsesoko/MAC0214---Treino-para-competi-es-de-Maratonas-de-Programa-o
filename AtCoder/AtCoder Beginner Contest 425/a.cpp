#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int n; cin >> n;
	int soma = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) soma += (i * i * i);
		else soma -= (i * i * i);
	}
	cout << soma << endl;
}
