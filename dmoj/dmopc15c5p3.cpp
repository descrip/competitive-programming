#include <bits/stdc++.h>
using namespace std;

int rev(int A, int B){
	int cnt = 0, R = 0;
	while (A > 0){
		R += (A % 10) * pow(B, cnt);
		++cnt;
		A /= 10;
	}
	return R;
}

int conv(int A, int B){
	string R = "";
	while (A > 0){
		R += '0' + A % B;
		//R = R * 10 + A % B;
		A /= B;
	}
	reverse(R.begin(), R.end());
	stringstream ss;
	ss << R;
	int Z; ss >> Z;
	return Z;
}

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int E, N; cin >> E >> N;
	static int A[10];
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	int T = A[N-1];
	for (int i = N-2; i >= 0; --i){
		T = rev(A[i], T);
		//cout << T << '\n';
	}
	cout << rev(E, T) << '\n';
return 0;}

