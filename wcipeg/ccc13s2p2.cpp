#include <iostream>
using namespace std;

struct node{
	int val, pos, win = -0xFFFFFFF;
	node *par;
	void merge(const node &a, const node &b){
		if (a.par->val > b.par->val){
			par = a.par; ++a.par->win;
		}
		else{
			par = b.par; ++b.par->win;
		}
	}
};

int N, M;
node tree[(1<<21)+1];

void build(int n){
	if ((1<<N) <= n) return;
	build(2*n); build(2*n+1);
	tree[n].merge(tree[2*n],tree[2*n+1]);
}

void update(int n, int p, int ow){
	if (n == 0) return;
	if (tree[ow].pos == tree[n].par->pos){
		if (tree[2*n].par->val > tree[2*n+1].par->val){
			--tree[ow].win;
			++tree[2*n].par->win;
			tree[n].par = tree[2*n].par;
			update(n/2,tree[2*n].par->pos+(1<<N),ow);
		}
		else{
			--tree[ow].win;
			++tree[2*n+1].par->win;
			tree[n].par = tree[2*n+1].par;
			update(n/2,tree[2*n+1].par->pos+(1<<N),ow);
		}
	}
	else if (tree[p].val > tree[n].par->val){
		--tree[n].par->win;
		++tree[p].win;
		tree[n].par = &tree[p];
		update(n/2,p,ow);
	}
}

int main(){
	cin >> N >> M;
	for (int i = (1<<N); i < (1<<(N+1)); ++i){
		cin >> tree[i].val;
		tree[i].win = 0;
		tree[i].par = &tree[i];
		tree[i].pos = i-(1<<N);
	}
	build(1);
	for (int i = 0; i < M; ++i){
		int a, b; char c;
		cin >> c;
		switch (c){
			case 'R':
				cin >> a >> b;
				tree[(1<<N)+a-1].val = b;
				update(((1<<N)+a-1)/2,(1<<N)+a-1,(1<<N)+a-1);
				break;
			case 'W':
				cout << tree[1].par->pos+1 << '\n';
				break;
			case 'S':
				cin >> a;
				cout << tree[(1<<N)+a-1].win << '\n';
				break;
		}
	}
	return 0;
}
