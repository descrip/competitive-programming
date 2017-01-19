#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(NULL));
	vector<int> L;
	int LEN; cin >> LEN;
	for (int i = 0; i < LEN; ++i)
		L.push_back(i);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(L.begin(), L.end(), std::default_random_engine(seed));
	int lenLCS, lenA, lenB; cin >> lenLCS >> lenA >> lenB;
	vector<int> A = L, B = L;
	seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(A.begin(), A.end(), std::default_random_engine(seed));
	seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(B.begin(), B.end(), std::default_random_engine(seed));
	L.erase(L.begin(), L.begin()+LEN-lenLCS);
	B.erase(B.begin(), B.begin()+LEN-lenB);
	A.erase(A.begin(), A.begin()+LEN-lenA);
	cout << lenA << '\n';
	for (int i = 0; i < lenA; ++i)
		cout << A[i] << " \n"[i==lenA-1];
	cout << lenB << '\n';
	for (int i = 0; i < lenB; ++i)
		cout << B[i] << " \n"[i==lenB-1];
return 0;}

