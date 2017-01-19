#include <bits/stdc++.h>
using namespace std;

bool solve(int n, vector<int> target) {
	reverse(target.begin(), target.end());
	vector<int> station, incoming;
	
	for (int i = n; i > 0; --i)
		incoming.push_back(i);
		
	while (true) {
		if (target.empty()) 
			return true;
		
		if (!station.empty() && target.back() == station.back()) {
			target.pop_back();
			station.pop_back();
		}
		else if (!incoming.empty() && target.back() == incoming.back()) {
			target.pop_back();
			incoming.pop_back();
		}
		else if (!incoming.empty()) {
			station.push_back(incoming.back());
			incoming.pop_back();
		}
		else return false;
	}
}

int main() {
	while (true) {
		int N; cin >> N;
		if (N == 0)
			break;
		vector<int> target;
		while (true) {
			target.resize(N);
			cin >> target[0];
			if (target[0] == 0)
				break;
			else {
				for (int i = 1; i < N; ++i)
					cin >> target[i];
				cout << (solve(N, target) ? "Yes" : "No") << '\n';
			}
		}
		cout << '\n';
	}
}
