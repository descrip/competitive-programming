#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int K;
  while (cin >> K) {
    if (K == 0)
      break;
    int M, N;
    cin >> M >> N;
    for (int i = 0; i < K; ++i) {
      int X, Y; cin >> X >> Y;
      if (X == M || Y == N)
        cout << "divisa\n";
      else if (X > M && Y > N)
        cout << "NE\n";
      else if (X < M && Y > N)
        cout << "NO\n";
      else if (X < M && Y < N)
        cout << "SO\n";
      else if (X > M && Y < N)
        cout << "SE\n";
    }
  }
return 0;}

