//TODO: Delete children

#include <iostream>
using namespace std;

struct node{
public:
	node* par, fall, cdn[4], next;
	char c;
	bool isEnd;
	
	node (char a) : c(a) {}
	
	void getChild(char a){
		int n = cn[a % 4];
		if (n == null) return null;
		while (n.next != null){
			if (n.c == s) return n;
			n = n.next;
		}
		if (n.c == s) return n;
		return null;
	}

	void addWord(string s){
		node n = getChild(s[0]);
		if (n == null){
			n = new TNode(s[0]);
			int pos = s[0] % 4;
			if (cn[pos] == null) cn[pos] = n;
			else{
				node no = cn[pos];
				while (no.next != null) no = no.next;
				no.next = n;
			}
		}
		if (s.size() > 1) n.addWord(s.substr(1,s.size()-1));
		else n.isEnd = true;
	}

	bool contains(string s){
		if (s.size() == 0) return isEnd;
		node n = getChild(s[0]);
		if (n == null) return false;
		else return n.contains(s.substr(1,s.size()-1));
	}
	
	void delChildren(){
		for (int i = 0; i < 4; ++i){
			
		}
	}
}

int K, Q;
string S, T;
node root;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> K;
	for (int tc = 0; tc < K; ++tc){
		cin >> S >> Q;
		for (int i = 0; i < Q; ++i){
			cin >> T;
			root.addWord(T);
		}
		root.fall = root;
	}
return 0;}
