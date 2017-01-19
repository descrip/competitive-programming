//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define NUM_TESTS 10

bool symbol(char c) {
  return !(
      ('a' <= c && c <= 'z') ||
      ('A' <= c && c <= 'Z') ||
      ('0' <= c && c <= '9')
    );
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  //freopen("data/DATA21.txt", "r", stdin);
  string S;
  for (int t = 1; t <= NUM_TESTS; ++t) {
    getline(cin, S);
    if (S[S.size()-1] == '\r')
      S = S.substr(0, S.size()-1);
    int ans = 0, cnt;
    
    ans += 4*S.size();

    if (S.size() >= 8) {
      cnt = 0;
      for (int i = 0; i < S.size(); ++i)
        if ('a' <= S[i] && S[i] <= 'z') {
          ++cnt;
          break;
        }
      for (int i = 0; i < S.size(); ++i)
        if ('A' <= S[i] && S[i] <= 'Z') {
          ++cnt;
          break;
        }
      for (int i = 0; i < S.size(); ++i)
        if ('0' <= S[i] && S[i] <= '9') {
          ++cnt;
          break;
        }
      for (int i = 0; i < S.size(); ++i)
        if (symbol(S[i])) {
          ++cnt;
          break;
        }
      //TODO: "Contains [at least] 3 of 4?"
      if (cnt >= 3)
        ans += 2+2*cnt;
    }

    cnt = 0;
    for (char c : S)
      if ('A' <= c && c <= 'Z')
        ++cnt;
    if (cnt > 0)
      ans += (S.size() - cnt) * 2;

    cnt = 0;
    for (char c : S)
      if ('a' <= c && c <= 'z')
        ++cnt;
    if (cnt > 0)
      ans += (S.size() - cnt) * 2;

    cnt = 0;
    for (char c : S)
      if ('0' <= c && c <= '9')
        ++cnt;
    if (cnt < S.size())
      ans += 4*cnt;

    cnt = 0;
    for (char c : S)
      if (symbol(c))
        ++cnt;
    ans += 6*cnt;

    cnt = 0;
    for (int i = 1; i < S.size()-1; ++i)
      if (('0' <= S[i] && S[i] <= '9') || symbol(S[i]))
        ++cnt;
    ans += 2*cnt;

    cnt = 0;
    for (char c : S)
      if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
        ++cnt;
    if (cnt == S.size())
      ans -= cnt;

    cnt = 0;
    for (char c : S)
      if ('0' <= c && c <= '9')
        ++cnt;
    if (cnt == S.size())
      ans -= cnt;

    for (int i = 0; i < S.size()-1; ++i)
      if ('A' <= S[i] && S[i] <= 'Z') {
        cnt = 1; int j;
        for (j = i+1; j < S.size(); ++j)
          if (!('A' <= S[j] && S[j] <= 'Z'))
            break;
          else
            ++cnt;
        ans -= 2*(cnt-1);
        i = j;
      }

    for (int i = 0; i < S.size()-1; ++i)
      if ('a' <= S[i] && S[i] <= 'z') {
        cnt = 1; int j;
        for (j = i+1; j < S.size(); ++j)
          if (!('a' <= S[j] && S[j] <= 'z'))
            break;
          else
            ++cnt;
        ans -= 2*(cnt-1);
        i = j;
      }

    for (int i = 0; i < S.size()-1; ++i)
      if ('0' <= S[i] && S[i] <= '9') {
        cnt = 1; int j;
        for (j = i+1; j < S.size(); ++j)
          if (!('0' <= S[j] && S[j] <= '9'))
            break;
          else
            ++cnt;
        ans -= 2*(cnt-1);
        i = j;
      }

    int best = 0;
    for (int i = 0; i < S.size()-1; ++i)
      if ('A' <= S[i] && S[i] <= 'Z') {
        cnt = 1; int j;
        for (j = i+1; j < S.size(); ++j)
          if ('A' <= S[j] && S[j] <= 'Z' && S[i]-(j-i) == S[j])
            ++cnt;
          else
            break;
        best = max(best, cnt);
        i = j-1;
      }
    if (best > 2)
      ans -= 3*(best-2);

    best = 0;
    for (int i = 0; i < S.size()-1; ++i)
      if ('A' <= S[i] && S[i] <= 'Z') {
        cnt = 1; int j;
        for (j = i+1; j < S.size(); ++j)
          if ('A' <= S[j] && S[j] <= 'Z' && S[i]+(j-i) == S[j])
            ++cnt;
          else
            break;
        best = max(best, cnt);
        i = j-1;
      }
    if (best > 2)
      ans -= 3*(best-2);

    best = 0;
    for (int i = 0; i < S.size()-1; ++i)
      if ('a' <= S[i] && S[i] <= 'z') {
        cnt = 1; int j;
        for (j = i+1; j < S.size(); ++j)
          if ('a' <= S[j] && S[j] <= 'z' && S[i]-(j-i) == S[j])
            ++cnt;
          else
            break;
        best = max(best, cnt);
        i = j-1;
      }
    if (best > 2)
      ans -= 3*(best-2);

    best = 0;
    for (int i = 0; i < S.size()-1; ++i)
      if ('a' <= S[i] && S[i] <= 'z') {
        cnt = 1; int j;
        for (j = i+1; j < S.size(); ++j)
          if ('a' <= S[j] && S[j] <= 'z' && S[i]+(j-i) == S[j])
            ++cnt;
          else
            break;
        best = max(best, cnt);
        i = j-1;
      }
    if (best > 2)
      ans -= 3*(best-2);

    best = 0;
    for (int i = 0; i < S.size()-1; ++i)
      if ('0' <= S[i] && S[i] <= '9') {
        cnt = 1; int j;
        for (j = i+1; j < S.size(); ++j)
          if (('0' <= S[j] && S[j] <= '9') && S[i]-(j-i) == S[j])
            ++cnt;
          else
            break;
        best = max(best, cnt);
        i = j-1;
      }
    if (best > 2)
      ans -= 3*(best-2);

    best = 0;
    for (int i = 0; i < S.size()-1; ++i)
      if ('0' <= S[i] && S[i] <= '9') {
        cnt = 1; int j;
        for (j = i+1; j < S.size(); ++j)
          if (('0' <= S[j] && S[j] <= '9') && S[i]+(j-i) == S[j])
            ++cnt;
          else
            break;
        best = max(best, cnt);
        i = j-1;
      }
    if (best > 2)
      ans -= 3*(best-2);

    ans = max(ans, 0);
    ans = min(ans, 100);

    if (ans >= 81)
      cout << "Very Strong ";
    else if (ans >= 61)
      cout << "Strong ";
    else if (ans >= 41)
      cout << "Good ";
    else if (ans >= 21)
      cout << "Weak ";
    else
      cout << "Very Weak ";

    cout << "(score = " << ans << ")\n";
  }
return 0;}

