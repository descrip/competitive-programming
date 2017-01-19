#include <bits/stdc++.h>
using namespace std;

struct classcomp {
  bool operator() (const pair<int,char>& lhs, const pair<int, char>& rhs) const {
    if (lhs.first == rhs.first)
      return lhs.second < rhs.second;
    return lhs.first > rhs.first;
  }
};

struct ColorfulGarden {

  vector<string> garden; 
  int cnt[27], tot[2];
  //set<pair<int, char>, greater<pair<int, char>>> res[2];
  set<pair<int,char>, greater<pair<int,char>>> res1;
  set<pair<int,char>, classcomp> res2;

  vector<string> rearrange(vector<string> garden) {
    this->garden = garden; 

    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < garden[0].size(); ++j)
        ++cnt[garden[i][j]-'a'];
    for (char c = 'a'; c <= 'z'; ++c)
      if (cnt[c-'a'] % 2 == 0) {
        res1.insert({cnt[c-'a']/2, c});
        res2.insert({cnt[c-'a']/2, c});
        tot[0] += cnt[c-'a']/2;
        tot[1] += cnt[c-'a']/2;
      }
      else {
        res1.insert({cnt[c-'a']/2 + (tot[0]<tot[1]), c});
        res2.insert({cnt[c-'a']/2 + (tot[1]<=tot[0]), c});
        bool what = tot[0]<tot[1];
        tot[0] += cnt[c-'a']/2 + what;
        tot[1] += cnt[c-'a']/2 + !what;
      }

    for (auto p : res1)
      cout << p.first << ' ' << p.second << '\n';
    cout << '\n';
    for (auto p : res2)
      cout << p.first << ' ' << p.second << '\n';

    vector<string> ans (2, garden[0]);
    for (int x = 0; x < garden[0].size(); ++x) {
      bool ok = false;
      for (auto p : res1)
        if (p.first == 0)
          return {};
        else if ((x == 0 || ans[0][x-1] != p.second)) {
          ans[0][x] = p.second;
          res1.insert({p.first-1, p.second});
          res1.erase(p);
          ok = true;
          break;
        }
      if (!ok)
        return {};
    }
    for (int x = 0; x < garden[0].size(); ++x) {
      bool ok = false;
      for (auto p : res2)
        if (p.first == 0)
          return {};
        else if ((x == 0 || ans[1][x-1] != p.second) && ans[0][x] != p.second) {
          ans[1][x] = p.second;
          res2.insert({p.first-1, p.second});
          res2.erase(p);
          ok = true;
          break;
        }
      if (!ok)
        return {};
    }

    return ans;
  }
};

// CUT begin
/* Greed Testing Code {{{ */
ifstream data("ColorfulGarden.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<string> garden, vector<string> __expected) {
    time_t startClock = clock();
    ColorfulGarden *instance = new ColorfulGarden();
    vector<string> __result = instance->rearrange(garden);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<string> garden;
        from_stream(garden);
        next_line();
        vector<string> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(garden, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1461427204;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "ColorfulGarden (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
/* }}} */
// CUT end
