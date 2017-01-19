#include <cstdio>
#include <algorithm>

typedef long long Long;

struct Line {
    Long a, b, get(Long x) { return a * x + b; }
};

struct ConvexHull {
    int size;
    Line *hull;

    ConvexHull(int maxSize) {
        hull = new Line[++maxSize], size = 0;
    }

    bool is_bad(Long curr, Long prev, Long next) {
        Line c = hull[curr], p = hull[prev], n = hull[next];
        return (c.b - n.b) * (c.a - p.a) <= (p.b - c.b) * (n.a - c.a);
    }

    void add_line(Long a, Long b) {
        hull[size++] = (Line){a, b};
        while (size > 2 && is_bad(size - 2, size - 3, size - 1))
            hull[size - 2] = hull[size - 1], size--;
    }

    Long query(Long x) {
        int l = -1, r = size - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (hull[m].get(x) <= hull[m + 1].get(x))
                l = m;
            else
                r = m;
        }
        return hull[r].get(x);
    }
};

const int N = (int)2e5 + 1;

int n, a[N];
Long sum[N];
Long ans, dans;
ConvexHull *hull;

int main() {
    scanf("%d", &n);

    hull = new ConvexHull(n);
    sum[0] = ans = dans = 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
        ans += a[i] * (long long)i;
    }

    hull->size = 0;
    for (int r = 2; r <= n; r++) {
        hull->add_line(r - 1, -sum[r - 2]);
        dans = std::max(dans, hull->query(a[r]) + sum[r - 1] - a[r] * (long long)r);
    }

    hull->size = 0;
    for (int l = n - 1; l >= 1; l--) {
        hull->add_line(-(l + 1), -sum[l + 1]);
        dans = std::max(dans, hull->query(-a[l]) + sum[l] - a[l] * (long long)l);
    }

    printf("%I64d", ans + dans);

    return 0;
}
