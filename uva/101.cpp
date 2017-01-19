#include <bits/stdc++.h>
using namespace std;

int N, L[26];
list<int> A[26];

list<int>::iterator sear(int a) {
  auto it = A[L[a]].begin();
  while (*it != a)
    ++it;
  return it;
}

void ret(list<int>::iterator it) {
  int e = L[*it]; ++it;
  while (it != A[e].end()) {
    A[*it].push_back(*it);
    L[*it] = *it;
    it = A[e].erase(it);
  }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    A[i].push_back(i);
    L[i] = i;
  }
  string s, t; int a, b;
  while (cin >> s) {
    if (s == "quit")
      break;
    cin >> a >> t >> b;
    if (a == b || L[a] == L[b])
      continue;
    auto ita = sear(a), itb = sear(b);
    if (s == "move")
      ret(ita);
    if (t == "onto")
      ret(itb);
    int tmp = L[a];
    while (ita != A[tmp].end()) {
      A[L[b]].push_back(*ita);
      L[*ita] = L[b];
      ita = A[tmp].erase(ita);
    }
  }
  for (int i = 0; i < N; ++i) {
    cout << i << ':';
    if (!A[i].empty())
      cout << ' ';
    for (int j : A[i])
      cout << j << " \n"[j == *A[i].rbegin()];
    if (A[i].empty())
      cout << '\n';
  }
return 0;}

