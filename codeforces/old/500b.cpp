#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> P(n);
	for (int i = 0; i < n; i++)
		cin >> P[i];
	vector<string> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	
	queue<int> q;
	vector<bool> vis(n,false);
	for (int k = 0; k < n; k++)
		if (!vis[k]){
			vector<int> C(1,k);
			q.push(k);
			vis[k] = true;
			while (!q.empty()){
				for (int i = 0; i < n; i++)
					if (A[q.front()][i] == '1' && !vis[i]){
						vis[i] = true;
						C.push_back(i);
						q.push(i);
					}
				q.pop();
			}
			for (int i : C)
				cout << i << ' ';
			cout << endl;
			sort(C.begin(),C.end());
			vector<int> p(C.size());
			for (int i = 0; i < C.size(); i++)
				p[i] = P[C[i]];
			sort(p.begin(),p.end());
			for (int i = 0; i < C.size(); i++)
				P[C[i]] = p[i];
		}

	for (int i = 0; i < n; i++)
		cout << P[i] << ((i == n - 1)?"\n":" ");
	return 0;
}
