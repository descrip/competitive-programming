// Copyright (C) 2016 Sayutin Dmitry.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; version 3

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; If not, see <http://www.gnu.org/licenses/>.


#include <iostream>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <string>
#include <assert.h>
#include <iterator>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::min;
using std::abs;
using std::max;

using std::sort;
using std::generate;
using std::min_element;
using std::max_element;

template <typename T>
T input() {
    T res;
    cin >> res;
    return res;
}

const size_t MAXN = (1 << 19);
vector<size_t> graph[MAXN];

vector<pair<size_t, size_t>> segm[2 * MAXN - 1];

#define time TIME_FUCKLIBC

pair<size_t, size_t> times[MAXN];
size_t time = 0;

size_t sizes[MAXN];

void dfs(size_t v) {
    size_t sz = 1;
    
    times[v].first = time++;

    for (size_t u: graph[v]) {
        dfs(u);
        sz += sizes[u];
    }
    
    times[v].second = time;
    segm[MAXN - 1 + times[v].first].emplace_back(sz, v);
    
    sizes[v] = sz;
}

void buildseg(size_t node, size_t L, size_t R) {
    if (L != R - 1) {
        size_t mid = L + (R - L) / 2;
        buildseg(2 * node + 1, L, mid);
        buildseg(2 * node + 2, mid, R);
        
        segm[node].resize(segm[2 * node + 1].size() + segm[2 * node + 2].size());
        std::merge(segm[2 * node + 1].begin(), segm[2 * node + 1].end(), segm[2 * node + 2].begin(), segm[2 * node + 2].end(), segm[node].begin());
    }
}

pair<size_t, size_t> lowerb(size_t node, size_t L, size_t R, size_t rl, size_t rr, pair<size_t, size_t> minval) {
    if (rl <= L and R <= rr) {
        auto it = std::lower_bound(segm[node].begin(), segm[node].end(), minval);
        if (it == segm[node].end())
            return make_pair(SIZE_MAX, SIZE_MAX);
        else
            return *it;
    }
    if (R <= rl or rr <= L)
        return make_pair(SIZE_MAX, SIZE_MAX);

    size_t mid = L + (R - L) / 2;
    return min(lowerb(2 * node + 1, L, mid, rl, rr, minval)
              ,lowerb(2 * node + 2, mid, R, rl, rr, minval));
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, q;
    cin >> n >> q;
    
    for (size_t i = 1; i != n; ++i)
        graph[input<size_t>() - 1].push_back(i);

    dfs(0);
    buildseg(0, 0, MAXN);
    
    for (size_t i = 0; i != q; ++i) {
        size_t v = input<size_t>() - 1;
        cout << lowerb(0, 0, MAXN, times[v].first, times[v].second, make_pair((sizes[v] + 1) / 2, 0)).second + 1 << "\n";
    }
    
    return 0;
}
