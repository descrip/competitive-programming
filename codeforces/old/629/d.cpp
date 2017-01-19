#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265359

const int SIZE = 100005;
long long A[SIZE];
map<pair<long long, int>, int> R;

long long sum(int i) // Returns the sum from index 1 to i
{
    long long sum = 0;
    while(i > 0) 
        sum += A[i], i -= i & -i;
    return sum;
}

long long wow(int i) // Returns the sum from index 1 to i
{
    long long wow = 0;
    while(i > 0) 
        wow = max(wow, A[i]), i -= i & -i;
    return wow;
}
 
void add(int i, long long k) // Adds k to element with index i
{
    while (i < SIZE) 
        A[i] += k, i += i & -i;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<pair<long long, int>> V (N);
	fill_n(A, SIZE, 0.0);
	for (int i = 0; i < N; ++i){
		long long a, b; cin >> a >> b;
		V[i] = {a*a*b, i};
	}
	auto W = V;
	sort(W.begin(), W.end());
	for (int i = 0; i < W.size(); ++i)
		R[W[i]] = i+1;
	for (int i = 1; i <= N; ++i)
		add(R[V[i-1]], V[i-1].first + (R[V[i-1]]-1 >= 1 ? wow(R[V[i-1]]-1) : 0));
	cout << fixed << setprecision(8) << wow(N)*PI << '\n';
return 0;}

