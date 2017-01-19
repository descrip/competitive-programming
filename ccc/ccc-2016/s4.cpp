#include <bits/stdc++.h>
using namespace std;

int N;
//map<list<int>, int> mem;
vector<int> V;
list<int> A;

int recur(){
	/*
	if (mem[A] != 0)
		return mem[A];
		*/
	int ret = 0;
	for (auto it = A.begin(); it != A.end(); ++it)
		ret = max(ret, *it);


	auto it3 = A.begin(), it2 = A.begin(), it1 = A.begin();
	//cout << *A.end() << '\n';

	if (A.size() >= 3){
		
	advance(it3,2);
	advance(it2,1);

	for (int i = 0; i < A.size()-2; ++i){

	cout << "A: ";
	for (auto it = A.begin(); it != A.end(); ++it)
		cout << *it << ' ';
	cout << '\n';
		cout << i << ' ' << *it1 << ' ' << *it2 << ' ' << *it3 << '\n';
		assert(it3 != A.end());

		if (*it1 == *it2){
			int a = *it1, b = *it2;
			A.erase(it1, it3);

			A.insert(it3, a+b);
			ret = max(ret, recur());
			auto it4 = it3;
			--it4;
			A.erase(it4);
			A.insert(it3, a);
			A.insert(it3, b);
		}

	cout << "B: ";
	for (auto it = A.begin(); it != A.end(); ++it)
		cout << *it << ' ';
	cout << '\n';
		cout << i << ' ' << *it1 << ' ' << *it2 << ' ' << *it3 << '\n';
		it2 = it3;
		--it2;
		it1 = it2;
		--it1;

		if (*it1 == *it3){
			auto it4 = it3;
			++it4;
			int a = *it1, b = *it2, c = *it3;
			A.erase(it1, it4);
			A.insert(it4, a+b+c);

			ret = max(ret, recur());
			auto it5 = it4;
			--it5;
			A.erase(it5);
			A.insert(it4, a);
			A.insert(it4, b);
			A.insert(it4, c);
		}

		it3++;
		it2 = it3;
		--it2;
		it1 = it2;
		--it1;
	}}

	it2 = A.end();
	--it2;
	it1 = it2;
	--it1;
		if (*it1 == *it2){
			int a = *it1, b = *it2;
			A.erase(it1, A.end());

			/*
			cout << "X: ";
	for (auto it = A.begin(); it != A.end(); ++it)
		cout << *it << ' ';
	cout << '\n';
	*/

			A.insert(A.end(), a+b);
			ret = max(ret, recur());
			auto it4 = A.end();
			--it4;
			A.erase(it4);
			A.insert(A.end(), a);
			A.insert(A.end(), b);
		}

	//mem[A] = ret;
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
	cout << recur() << '\n';
return 0;}

