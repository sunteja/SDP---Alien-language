#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string succ_alien(string n, string b) {
	unordered_map<char, string> m;
	unordered_map<char, char> mdup;
	string str = "";
	for (ll i = 0; i < b.length(); i++) {
		m[b[i]] = to_string(i);
	}
	for (ll i = 0; i < b.length(); i++) {
		mdup[i + '0'] = b[i];
	}
	for (ll i = 0; i < n.length(); i++) {
		str = str + m[n[i]];
	}
	// cout << "The string so far is " << str << endl;
	ll i = n.length() - 1;
	ll c = 0;
	while (i >= 0) {
		//cout << "Iter i value is " << i << endl;
		char old = str[i];
		//cout << "Old value: " << old << endl;
		if (i == n.length() - 1)
			str[i] = (c + (old - '0') + 1) % (b.length()) + '0';
		else {
			str[i] = (c + (old - '0')) % (b.length()) + '0';
		}
		// cout << "char value: " << str[i] << endl;
		c = ((old - '0') + 1) / (b.length());
		i--;
	}
	//cout << str << endl;
	for (ll i = 0; i < n.length(); i++) {
		str[i] = mdup[str[i]];
	}
	if (c >= 1) {
		cout << "Overflow detected... Answer cannot be given with the bits and the alien symbols given. Need another extra symbol... adding another bit '#' by default to represent the carry value: " << c << endl;
		str = n[c+'0'] + str;
	}
	return str;
}

int main() {
	string n, b;
	cin >> n >> b;
	cout << succ_alien(n, b) << endl;
}
