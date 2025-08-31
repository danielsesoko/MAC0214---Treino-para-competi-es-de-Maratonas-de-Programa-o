#include<bits/stdc++.h>
using namespace std;
#define int long long

int f(int a) {
	string s = to_string(a);
	reverse(s.begin(), s.end());
	return stoll(s);
}

signed main() {
	int a[11];
	cin >> a[1] >> a[2];
	
	for (int i = 3; i <= 10; i++) {
		a[i] = f(a[i-1] + a[i-2]);
	}
	cout << a[10] << endl;
}
