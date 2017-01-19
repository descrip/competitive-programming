#include <bits/stdc++.h>
using namespace std;

int T;
double P, X, Y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        cin >> P >> X >> Y;
        double dist2 = (X-50)*(X-50) + (Y-50)*(Y-50);
        if (dist2 > 50*50) cout << "white\n";
        else {
            double deg = atan2(Y-50, X-50);
            //cout << fmod(-(deg/M_PI*180 - 90) + 360, 360) << '\n';
            //cout << fmod(fmod(-(deg/M_PI*180-90), 360)+360, 360) << '\n';
            cout << (fmod(fmod(-(deg/M_PI*180-90), 360)+360, 360) <= P/100*360 ? "black" : "white") << '\n'; 
        }
    }
    return 0;
}

