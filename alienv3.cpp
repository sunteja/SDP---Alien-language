// In this code there are better variable names and the variables which are getting repeated often like b.length() and n.length() are taken into other variable names like bl, nl etc. This makes the code more understandable and clean. Moreover, the variable names like symtonstr, nchartosym, answer are meaningful as the former is a map which stores the mapping from symbols to string of numbers and the latter stores the mapping from integer characters like '1', '2' to the alien symbols.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string succ_alien(string n, string b) {
	unordered_map<char, string> symtonstr;
	unordered_map<char, char> nchartosym;
	ll bl = b.length();
	ll nl = n.length();
	string answer = "";
	for (ll i = 0; i < bl; i++) {
		symtonstr[b[i]] = to_string(i);
	}
	for (ll i = 0; i < bl; i++) {
		nchartosym[i + '0'] = b[i];
	}
	for (ll i = 0; i < nl; i++) {
		answer = answer + symtonstr[n[i]];
	}
	ll i = nl - 1;
	ll carry = 0;
	while (i >= 0) {
		char old = answer[i];
		if (i == nl - 1)
			answer[i] = (carry + (old - '0') + 1) % (bl) + '0';
		else {
			answer[i] = (carry + (old - '0')) % (bl) + '0';
		}
		carry = ((old - '0') + 1) / (bl);
		i--;
	}
	for (ll i = 0; i < nl; i++) {
		answer[i] = nchartosym[answer[i]];
	}
	if (carry >= 1) {
		cout << "Overflow detected..." << endl;
		answer = nchartosym[carry + '0'] + answer;
	}
	return answer;
}

int main() {
	string n, b;
	cin >> n >> b;
	cout << succ_alien(n, b) << endl;
}
