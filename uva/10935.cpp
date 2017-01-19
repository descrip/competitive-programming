#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (cin >> N) {
        if (N == 0) break;
        deque<int> dq;
        for (int i = 1; i <= N; ++i)
            dq.push_back(i);
        cout << "Discarded cards:";
        while (dq.size() > 1) {
            cout << ' ' << dq.front() << (dq.size() == 2 ? "" : ",");
            dq.pop_front();
            dq.push_back(dq.front());
            dq.pop_front();
        }
        cout << "\nRemaining card: " << dq.front() << '\n';
    }
	return 0;
}

