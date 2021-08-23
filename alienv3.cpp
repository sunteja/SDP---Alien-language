// In this code all the functions are written independently of each other. The numtoal function converts a string from the integer string to the corresponding alien string. On the other hand, the altonum does the reverse. The succutil function is a utility function which adds 1 to the string given to it and stores it in the original string itself
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void numtoal(string &str, unordered_map<char, char> n) {
	ll nl = str.length();
	for (ll i = 0; i < nl; i++) {
		str[i] = n[str[i]];
	}
}

string altonum(string str, unordered_map<char, string> m) {
	ll nl = str.length();
	string answer = "";
	for (ll i = 0; i < nl; i++) {
		answer = answer + m[str[i]];
	}
	return answer;
}

void succutil(string &str, ll bl) {
	ll nl = str.length();
	ll i = nl - 1;
	ll carry = 0;
	while (i >= 0) {
		char old = str[i];
		if (i == nl - 1)
			str[i] = (carry + (old - '0') + 1) % (bl) + '0';
		else {
			str[i] = (carry + (old - '0')) % (bl) + '0';
		}
		carry = ((old - '0') + 1) / (bl);
		i--;
	}
	if (carry >= 1) {
		cout << "Overflow detected..." << endl;
		str = to_string(carry) + str;
	}
}
string succ_alien(string n, string b) {
	unordered_map<char, string> symtonstr;
	unordered_map<char, char> nchartosym;
	ll bl = b.length();
	ll nl = n.length();
	for (ll i = 0; i < bl; i++) {
		symtonstr[b[i]] = to_string(i);
	}
	for (ll i = 0; i < bl; i++) {
		nchartosym[i + '0'] = b[i];
	}
	string answer = altonum(n, symtonstr);
	succutil(answer, bl);
	numtoal(answer, nchartosym);
	return answer;
}

int main() {
	string n, b;
	cin >> n >> b;
	cout << succ_alien(n, b) << endl;
}
