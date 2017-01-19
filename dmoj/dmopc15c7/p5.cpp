#include <bits/stdc++.h>
using namespace std;

int N, Q, id2rn[100005], rn2id[100005], par[100005], dist[100005];
vector<int> adj[100005];
pair<int, int> ran[100005];
bool visU[100005], visV[100005];

void setDist(int n, int d) {
  dist[id2rn[n]] = d;
  for (int v : adj[n])
    setDist(v, d+1);
}

int recur(int n, int renum) {
  //cout << n << '\n';
  rn2id[renum] = n;
  ran[renum].first = renum;
  int tmp = renum;
  id2rn[n] = renum++;
  for (int v : adj[n])
    renum = recur(v, renum);
  ran[tmp].second = renum-1;
  return renum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    int C; cin >> C;
    for (int j = 0; j < C; ++j) {
      int a; cin >> a;
      adj[i].push_back(a);
      par[a] = i;
    }
  }

  recur(1, 1);
  setDist(1, 0);
  /*
  for (int i = 1; i <= N; ++i) {
    cout << i << ' ';
    for (int j : adj[rn2id[i]])
      cout << id2rn[j] << ' ';
    cout << ran[i].first << ' ' << ran[i].second << '\n';
    cout << '\n';
  }
  */

  int Q; cin >> Q;
  for (int q = 0; q < Q; ++q) {
    int U, V; cin >> U >> V;
    U = id2rn[U]; V = id2rn[V];
    int cntU = 0, cntV = 0, u = U, v = V;
    fill_n(visU, 100005, false);
    fill_n(visV, 100005, false);
    while (true) {
      //cout << u << ' ' << v << ' ' << cntU << ' ' << cntV << '\n';
      visU[u] = visV[v] = true;
      if (v == U && cntV <= cntU) {
        cout << cntV << '\n';
        break;
      }
      else if (v != U) {
        int i = adj[rn2id[v]].size()-1;
        for (; i >= 0; --i) {
          int a = id2rn[adj[rn2id[v]][i]];
          if (visV[a])
            continue;
          else if (U < ran[a].first || ran[a].second < U)
            cntV += (ran[a].second - ran[a].first + 1) * 2;
          else if (ran[a].first <= U && U <= ran[a].second) {
            //cout << cntV << '\n';
            //cout << (U - ran[a].first + 1) * 2 << ' ' << dist[U] - dist[a] << '\n';
            cntV += (U - ran[a].first + 1) * 2 - (dist[U] - dist[v]);
            //cout << cntV << '\n';
            v = U;
            break;
          }
          else if (a == *adj[rn2id[v]].begin()) {
            v = id2rn[par[rn2id[v]]];
            break;
          }
        }
        if (i == -1) {
          v = id2rn[par[rn2id[v]]];
          ++cntV;
        }
      }
      if (u == V && cntU <= cntV) {
        cout << cntU << '\n';
        break;
      }
      else if (u != V) {
        int i = 0;
        for (; i < adj[rn2id[u]].size(); ++i) {
          int a = id2rn[adj[rn2id[u]][i]];
          //cout << a << ' ' << visU[a] << ' ' << ran[a].first << ' ' << ran[a].second << ' ';
          if (visU[a])
            continue;
          else if (ran[a].second < V || V < ran[a].first)
            cntU += (ran[a].second - ran[a].first + 1) * 2;
          else if (ran[a].first <= V && V <= ran[a].second) {
            cntU += (V - ran[a].first + 1) * 2 - (dist[V] - dist[u]);
            u = V;
            break;
          }
        }
        //cout << i << '\n';
        if (i == adj[rn2id[u]].size()) {
          u = id2rn[par[rn2id[u]]];
          ++cntU;
        }
      }
    }
  }
return 0;}

