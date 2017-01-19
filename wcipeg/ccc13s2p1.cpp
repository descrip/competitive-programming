#include <cmath>
#include <deque>
#include <iostream>
using namespace std;

const int MAX = 1000000000;

bool val(int x, int b){
	deque<int> v;
	while (x){
		v.push_front(x % b);
		x /= b;
	}
	for (int i = 0; i < v.size()/2; ++i)
		if (v[i] != v[v.size()-i-1]) 
			return false;
	return true;
}

int main(){
	int X; cin >> X;
	for (int i = 2; i <= sqrt(MAX) && X > i; ++i)
		if (val(X,i)) cout << i << '\n';
	if (X > sqrt(MAX)){
		for (int i = X/sqrt(MAX); i > 0; --i)
			if (X % i == 0)
				cout << X / i - 1 << '\n';
	}
	return 0;
}
