#include <bits/stdc++.h>
using namespace std;

// had some fun with inheritance since i dont do a lot of oop with c++

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

class Shape {
    public:
        virtual bool contains(double x, double y) {}
};

class Circle: public Shape {
    double cx, cy, r;
    public:
        Circle(double x, double y, double rad) : cx(x), cy(y), r(rad) {}
        bool contains(double x, double y) {
            return dist(cx, cy, x, y) < r;
        }
};

class Rectangle: public Shape {
    double ax, ay, bx, by;
    public:
        Rectangle(double x1, double y1, double x2, double y2) : ax(x1), ay(y1), bx(x2), by(y2) {}
        bool contains(double x, double y) {
            return (ax < x && x < bx && ay > y && y > by);
        }
};

vector<Shape *> S;

int main() {
    for (int i = 0; i < 10; ++i) {
        char c; scanf(" %c", &c);
        if (c == '*') break;
        else if (c == 'r') {
            double x1, y1, x2, y2; 
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            S.push_back(new Rectangle(x1, y1, x2, y2));
        }
        else if (c == 'c') {
            double x, y, r;
            scanf("%lf %lf %lf", &x, &y, &r);
            S.push_back(new Circle(x, y, r));
        }
        if (i == 9)
            scanf(" %c", &c);
    }
    double x, y; int cnt = 0;
    while (scanf("%lf %lf", &x, &y) != EOF) {
        //printf("%lf %lf\n", x, y);
        bool ok = false;
        if (x == 9999.9 && y == 9999.9) break;
        for (int i = 0; i < S.size(); ++i)
            if (S[i]->contains(x, y)) {
                printf("Point %d is contained in figure %d\n", cnt+1, i+1);
                ok = true;
            }
        if (!ok)
            printf("Point %d is not contained in any figure\n", cnt+1);
        ++cnt;
    }
	return 0;
}

