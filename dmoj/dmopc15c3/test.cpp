#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int cnt = 0;
    while (cnt % 1000 || clock() < 1000) ++cnt;
    cout << cnt << "\n";
}
