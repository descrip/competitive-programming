#include <iostream>
#include <algorithm>
using namespace std;

int A, B, C, N, M;
int S[100001], sums[100001];

inline int func(int n){
	return (sums[n]-n-1)*B + (sums[N-1]-sums[n]-(N-n-1))*A + (1+N-n-2)*(N-n-2)*C/2;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> A >> B >> C;
	for (int i = 0; i < N; ++i) cin >> S[i];
	sort(S,S+N);
	sums[0] = S[0];
	for (int i = 1; i < N; ++i) sums[i] = sums[i-1] + S[i];
	int ans = 0x7FFFFFFF;
	for (int i = -1; i < N; ++i) ans = min(ans,func(i));
	//ans = min(ans,(sums[N-1]-N)*A+(N)*(N-1)*C/2);
	cout << ans << '\n';
return 0;}
