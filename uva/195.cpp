#include <bits/stdc++.h>
using namespace std;

// ambiguous problem statements ):

/*
bool charcomp() (const char &a, const char &b) const {
	if (tolower(a) == tolower(b)) return a < b;
	else return tolower(a) < tolower(b);
}
*/

struct stringcomp {
	bool operator() (const string &a, const string &b) {
		int l = min(a.size(), b.size());
		for (int i = 0; i < l+1; ++i) {
			if (i == l)
				return a.size() < b.size();
			else if (a[i] == b[i])
				continue;
			else if (tolower(a[i]) == tolower(b[i]))
				return a < b;
			else return tolower(a[i]) < tolower(b[i]);
		}
	} 
};

int main() {
	int N; set<string, stringcomp> Z;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		Z.clear();
		string S; cin >> S;
		sort(S.begin(), S.end());
		do {
			Z.insert(S);
		} while (next_permutation(S.begin(), S.end()));
		for (string s : Z)
			cout << s << '\n';
	}
}
