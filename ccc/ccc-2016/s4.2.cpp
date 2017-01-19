#include <bits/stdc++.h>
using namespace std;

int N;
map<list<int>, int> mem;
vector<int> V;
list<int> A;

int recur(list<int> A){
	if (mem[A] != 0)
		return mem[A];
	int ret = 0;
	for (auto it = A.begin(); it != A.end(); ++it)
		ret = max(ret, *it);

	/*
		for (int i : A)
			cout << i << ' ';
		cout << '\n';
		*/

	auto it1 = A.begin(), it2 = A.begin(), it3 = A.begin();
	advance(it3, 2); advance(it2, 1);
	if (A.size() >= 3) for (int i = 0; i < A.size()-2; ++i){
		/*
		for (int i : A)
			cout << i << ' ';
		cout << '\n';
		cout << i << ' '  << *it1 << ' ' << *it2 << ' ' << *it3 << '\n';
		*/
		assert(it3 != A.end());
		if (*it1 == *it2){
			int a = *it1, b = *it2;
			A.erase(it1, it3);
			A.insert(it3, a+b);
			ret = max(ret, recur(A));
			auto it4 = it3;
			advance(it4, -1);
			A.erase(it4);
			A.insert(it3, a);
			A.insert(it3, b);
		}
		it2 = it3; advance(it2, -1);
		it1 = it2; advance(it1, -1);
		/*
		for (int i : A)
			cout << i << ' ';
		cout << '\n';
		cout << i << ' '  << *it1 << ' ' << *it2 << ' ' << *it3 << '\n';
		*/
		assert(it3 != A.end());
		if (*it1 == *it3){
			int a = *it1, b = *it2, c = *it3;
			auto it4 = it3; advance(it4, 1);
			A.erase(it1, it4);
			A.insert(it4, a+b+c);
			ret = max(ret, recur(A));
			auto it5 = it4;
			advance(it5, -1);
			A.erase(it5);
			A.insert(it4, a);
			A.insert(it4, b);
			A.insert(it4, c);
			it3 = it4; advance(it3, -1);
		}
		it2 = it3;
		it1 = it2;
		advance(it3,1);
	}

	it2 = A.end(); --it2;
	it1 = it2; --it1;
	if (*it1 == *it2){
		int a = *it1, b = *it2;
		A.erase(it1, A.end());
		A.insert(A.end(), a+b);
		ret = max(ret, recur(A));
		auto it4 = A.end();
		advance(it4, -1);
		A.erase(it4);
		A.insert(A.end(), a);
		A.insert(A.end(), b);
	}

	mem[A] = ret;
	return ret;
}

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i){
		int a; cin >> a;
		V.push_back(a);
	}
	A.assign(V.begin(), V.end());
	cout << recur(A) << '\n';
return 0;}

