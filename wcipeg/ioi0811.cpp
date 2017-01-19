#include <iostream>
#include <algorithm>
using namespace std;

struct node {
  node* chi[26];
  bool fin;
  int len;
  char chr;
  node(char c) : fin(false), len(1), chr(c) {
    for (int i = 0; i < 26; ++i)
      chi[i] = 0;
  }
};

int N, best = 0;
string S, ans;
node* root;

void add(node* curr, const string &str, int pos) {
  if (pos == str.size()) {
    curr->fin = true;
    return;
  }
  int idx = str[pos] - 'a';
  if (!curr->chi[idx])
    curr->chi[idx] = new node(str[pos]);
  add(curr->chi[idx], str, pos+1);
  curr->len = max(curr->len, curr->chi[idx]->len + 1);
}

bool lensort(node* a, node* b) {
  if (!b)
    return false;
  if (!a)
    return true;
  return (a->len) < (b->len);
}

void gao(node* n) {
  if (!n)
    return;

  ++best;
  ans += n->chr;
  if (n->fin) {
    ans += 'P';
    ++best;
  }

  sort(n->chi, n->chi+26, lensort);
  for (int i = 0; i < 26; ++i)
    gao(n->chi[i]);

  ++best;
  ans += '-';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  root = new node('0');
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> S;
    add(root, S, 0);
  }
  gao(root);

  --best;
  ans = ans.substr(1);
  int pos = ans.size()-1;
  while (ans[pos] == '-')
    --pos;
  ++pos;
  best -= (ans.size() - pos);
  ans = ans.substr(0, pos);

  cout << best << '\n';
  for (char c : ans)
    cout << c << '\n';
return 0;}

