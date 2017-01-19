#include <iostream>
#include <vector>
using namespace std;

int main(){
	int K, m;
	cin >> K >> m;
	
	vector<int> v;
	for (int i = 1; i <= K; i++)
		v.push_back(i);
	
	int n, p;
	for (int i = 0; i < m; i++){
		cin >> n;
		for (int j = 1; j < 100; j++){
			p = n * j;
			if (p > v.size())
				break;
			else
				v[p-1] = -1;
		}
		for (int j = v.size() - 1; j >= 0; j--)
			if (v[j] == -1)
				v.erase(v.begin() + j);
	}

	for (int i : v)
		cout << i << endl;
	
	return 0;	
}
