#include <bits/stdc++.h>
using namespace std;

// why would anyone have input this horrible
// also why didn't they tell us that there were negative numbers
// also why am i dumb

struct node {
    int left, right, val;
    bool leaf = false;
    node (int a, int b, int c) : left(a), right(b), val(c) {}
    node (bool b) : leaf(b) {}
};
int sum;
bool ans;
vector<node> A;

int construct() {
    char c; scanf(" %c", &c);
    int val; 
    if (scanf(" %d", &val) == 0)
        A.push_back(node(true));
    else
        A.push_back(node(construct(), construct(), val));
    scanf(" %c", &c);
    return A.size()-1;
}

void dfs(int u, int sf) {
    if (A[u].leaf) return;
    else if (A[A[u].left].leaf && A[A[u].right].leaf)
        ans = ans | (sf + A[u].val == sum);
    else {
        dfs(A[u].left, sf + A[u].val);
        dfs(A[u].right, sf + A[u].val);
    }
}

int main() {
    while (scanf(" %d", &sum) != EOF) {
        A.clear();
        construct();
        ans = false;
        dfs(A.size()-1, 0);
        printf("%s\n", (ans ? "yes" : "no"));
    }
	return 0;
}

