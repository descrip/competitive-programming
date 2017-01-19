#include <bits/stdc++.h>
using namespace std;

int M, N, X, Y, Cx, Cy;
char C;
string S;
set<pair<int, int>> smelly;

char toCard(int cx, int cy) {
    if (cy == 0) return (cx == 1 ? 'E' : 'W');
    else return (cy == 1 ? 'N' : 'S');
}

pair<int, int> fromCard(char c) {
    if (c == 'N') return {0, 1};
    else if (c == 'S') return {0, -1};
    else if (c == 'E') return {1, 0};
    else if (c == 'W') return {-1, 0};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> M >> N;
    while (cin >> X >> Y >> C) {
        cin >> S;
        auto Cp = fromCard(C);
        Cx = Cp.first; Cy = Cp.second;
        bool lost = false;
        for (char a : S) {
            //cout << X << ' ' << Y << ' ' << Cx << ' ' << Cy << '\n';
            if (a == 'F') {
                int Nx = X + Cx, Ny = Y + Cy;
                if (Nx > M || Ny > N || Nx < 0 || Ny < 0) {
                    if (smelly.count(make_pair(X, Y)) == 0) {
                        cout << X << ' ' << Y << ' ' << toCard(Cx, Cy) << " LOST\n";
                        smelly.insert({X, Y});
                        lost = true;
                        break;
                    }
                    else continue;
                }
                else {
                    X = Nx; Y = Ny;
                }
            }
            else if (a == 'R') {
                int z = Cx; Cx = Cy; Cy = -z;
            }
            else if (a == 'L') {
                int z = Cx; Cx = -Cy; Cy = z;
            }
        }
        if (!lost)
            cout << X << ' ' << Y << ' ' << toCard(Cx, Cy) << '\n';
    }
	return 0;
}

