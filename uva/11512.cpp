#include <bits/stdc++.h>
using namespace std;

struct node{
	int cnt = 0;
	struct node *chi[4];
} *head;
map<char,int> m;
string str, ans;
int len, occ;

void add(int a){
	node *curr = head;
	for (int i = a; i < str.size(); ++i){
		if (curr->chi[m[str[i]]] == NULL)
			curr->chi[m[str[i]]] = new node();
		curr = curr->chi[m[str[i]]];
		++curr->cnt;
		if (curr->cnt >= 2 && i-a+1 > len){
			ans = str.substr(a,i-a+1);
			len = i-a+1;
			occ = curr->cnt;
		}
		else if (curr->cnt >=2 && i-a+1 == len && str.substr(a,i-a+1) <= ans){
			ans = str.substr(a,i-a+1);
			len = i-a+1;
			occ = curr->cnt;
		}
	}
}

void del(node *n){
	for (int i = 0; i < 4; ++i)
		if (n->chi[i])
			del(n->chi[i]);
	delete n;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	m['A'] = 0;
	m['C'] = 1;
	m['G'] = 2;
	m['T'] = 3;
	while (t--){
		cin >> str;
		ans = ""; occ = len = 0;
		head = new node();
		for (int i = 0; i < str.size(); ++i)
			add(i);
		for (int i = 0; i < 4; ++i)
			if (head->chi[i])
				del(head->chi[i]);
		if (occ == 0)
			cout << "No repetitions found!\n";
		else
			cout << ans << ' ' << occ << '\n';
	}
return 0;}
