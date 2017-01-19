#include <set>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;

int n;
map<char,char> curr;
vector<pair<char,char>> maps;
set<char> bef;

bool perm(const string &s, const string &t, int pos){
	if (pos == n){
		for (int i = 0; i < n; ++i)
			for (int j = i+1; j < n; ++j)
				if (i != j)
					if (curr[97+i] == curr[97+j])
						return false;
		return true;
	}
	char c = 97+pos;
	if (curr.count(c) == 0){
		curr[c] = maps[pos].first;
		if (perm(s,t,pos+1))
			return true;
		curr[c] = maps[pos].second;
		if (perm(s,t,pos+1))
			return true;
		curr.erase(c);
		return false;
	}
	else
		return perm(s,t,pos+1);
}

bool cando(const string &s, const string &t, int pos){
	if (pos == s.length())
		return perm(s,t,0);
	if (curr.count(s[pos]) == 0){
		if (bef.count(t[pos]) == 0){
			curr[s[pos]] = t[pos];
			bef.insert(t[pos]);
		}
		else{
			return false;
		}
	}
	return cando(s,t,pos+1);
}

int main(){
	cin >> n;
	for (int i = 0; i < n; ++i){
		char a, b;
		cin >> a >> b;
		maps.pb({a,b});
	}
	int a;
	cin >> a;
	for (int i = 0; i < a; ++i){
		string s, t;
		cin >> s >> t;
		bool ok = true;
		for (int j = 0; j < s.length() && ok; ++j){
			if (!(maps[s[j]-97].first == t[j] || maps[s[j]-97].second == t[j]))
				ok = false;
			for (int k = j+1; k < s.length() && ok; ++k)
				if (s[j] == s[k])
					if (t[j] != t[k])
						ok = false;
		}
		if (!ok)
			cout << "NO" << endl;
		else
			cout << (cando(s,t,0) ? "YES" : "NO") << endl;
		curr.clear();
		bef.clear();
	}
}
