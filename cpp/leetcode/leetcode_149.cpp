#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x;
    int y;
    point(): x(0), y(0) {}
    point(int a, int b): x(a), y(b) {}
};

bool equal(const Point& a, const Point& b) {
    return a.x == b.x && a.y == b.y;
}
int gcd(int a, int b) {
    int r;
    if (a < b) swap(a, b);
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
};
typedef pair<int, int> slope_t;
int maxPoints(vector<Point>& points) {
    if (points.size() <= 2) return points.size();
    int max_p = 0;
    for (int i = 0; i < points.size(); i++) {
        map<slope_t, int> lines;
        int dup = 0, vertical = 0;
        int local_max = 0;
        for (int j = i + 1; j < points.size(); j++) {
            if (equal(points[i], points[j])) {
                dup++;
                continue;
            } else if (points[i].x == points[j].x) {
                vertical++;
            } else {
                int delta_x = points[i].x - points[j].x;
                int delta_y = points[i].y - points[j].y;
                int t = gcd(abs(delta_x), abs(delta_y));
                int sign = (delta_x ^ delta_y) >> 31;
                delta_x /= t; delta_y /= t;
                delta_x = abs(delta_x); delta_y = abs(delta_y);
                if (sign) delta_y = -delta_y;
                slope_t slope(delta_y, delta_x);
                lines[slope]++;
                local_max = max(local_max, lines[slope]);
            }
            local_max = max(local_max, vertical);
        }
        max_p = max(max_p, local_max + dup + 1);
    }
    return max_p;
}

int main() {
    vector<point> points = {{0, 0}, {1, 0}, {1, -1}, {2, 0}, {3, 3}, {1, 4}, {4, 0}, {1, 6}};
    cout << max_points(points) << endl;
    cout << gcd(0, 1) << " " << gcd(5, 0) << endl;
}