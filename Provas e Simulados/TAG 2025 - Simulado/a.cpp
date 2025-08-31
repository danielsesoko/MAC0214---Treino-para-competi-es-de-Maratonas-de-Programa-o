#include<bits/stdc++.h>
using namespace std;

bool t, a ,p;

signed main() {
	string s; cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'T') t = 1;
		if (s[i] == 'A' and t == 1) a = 1;
		if (s[i] == 'P' and t == 1 and a == 1) p = 1;
	}

	if (t and a and p) cout << "S";
	else cout << "N";
}

