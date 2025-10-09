#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> Point;

Point operator-(const Point& a, const Point& b) {
    return {a.first - b.first, a.second - b.second};
}

LL cross_product(const Point& o, const Point& a, const Point& b) {
    Point oa = a - o;
    Point ob = b - o;
    return oa.first * ob.second - oa.second * ob.first;
}

vector<Point> andrew_convex_hull(vector<Point> points) {
    if (points.size() <= 1) {
        return points;
    }

    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    vector<Point> lower;
    for (int i = 0; i < points.size(); i++) {
        while (lower.size() >= 2) {
            Point a = lower[lower.size()-2];
            Point b = lower.back();
            Point c = points[i];
            if (cross_product(a, b, c) <= 0) {
                lower.pop_back();
            } else {
                break;
            }
        }
        lower.push_back(points[i]);
    }

    vector<Point> upper;
    for (int i = points.size()-1; i >=0; i--) {
        while (upper.size() >= 2) {
            Point a = upper[upper.size()-2];
            Point b = upper.back();
            Point c = points[i];
            if (cross_product(a, b, c) <= 0) {
                upper.pop_back();
            } else {
                break;
            }
        }
        upper.push_back(points[i]);
    }

    if (!lower.empty()) lower.pop_back();
    if (!upper.empty()) upper.pop_back();

    vector<Point> hull;
    hull.reserve(lower.size() + upper.size());
    for (auto &p : lower) {
        hull.push_back(p);
    }
    for (auto &p : upper) {
        hull.push_back(p);
    }
    return hull;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Point> poly;
        for (int i = 0; i < n; i++) {
            LL x, y;
            cin >> x >> y;
            poly.push_back({x, y});
        }

        vector<Point> new_poly;
        for (int i = 0; i < n; i++) {
            if (i == 0 || poly[i] != poly[i-1]) {
                new_poly.push_back(poly[i]);
            }
        }
        if (!new_poly.empty() && new_poly[0] == new_poly.back()) {
            new_poly.pop_back();
        }
        n = new_poly.size();

        set<Point> distinct_points;
        for (const auto& pt : new_poly) {
            distinct_points.insert(pt);
        }

        set<Point> hull_set;
        if (distinct_points.size() == 1) {
            hull_set = distinct_points;
        } else if (!distinct_points.empty()) {
            // Group by x, and for each x, record min_y and max_y.
            vector<Point> extreme_points;
            {
                set<LL> xs;
                for (const auto& pt : distinct_points) {
                    xs.insert(pt.first);
                }
                vector<LL> x_vec(xs.begin(), xs.end());
                vector<pair<LL, pair<LL, LL>>> by_x;
                for (LL x : x_vec) {
                    by_x.push_back({x, {0, 0}});
                }
                for (const auto& pt : distinct_points) {
                    auto it = lower_bound(x_vec.begin(), x_vec.end(), pt.first);
                    int idx = it - x_vec.begin();
                    if (by_x[idx].second.first == by_x[idx].second.second && by_x[idx].second.first == 0) {
                        by_x[idx].second = {pt.second, pt.second};
                    } else {
                        if (pt.second < by_x[idx].second.first) {
                            by_x[idx].second.first = pt.second;
                        }
                        if (pt.second > by_x[idx].second.second) {
                            by_x[idx].second.second = pt.second;
                        }
                    }
                }
                for (const auto& item : by_x) {
                    extreme_points.push_back({item.first, item.second.first});
                    if (item.second.first != item.second.second) {
                        extreme_points.push_back({item.first, item.second.second});
                    }
                }
            }

            vector<Point> hull_list = andrew_convex_hull(extreme_points);
            for (const auto& pt : hull_list) {
                hull_set.insert(pt);
            }
        }

        vector<Point> nails;
        if (n >= 3) {
            for (int i = 0; i < n; i++) {
                Point a = new_poly[(i-1+n) % n];
                Point b = new_poly[i];
                Point c = new_poly[(i+1) % n];
                Point v1 = {b.first - a.first, b.second - a.second};
                Point v2 = {c.first - b.first, c.second - b.second};
                LL cross = v1.first * v2.second - v1.second * v2.first;
                if (cross != 0) {
                    nails.push_back(b);
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                nails.push_back(new_poly[i]);
            }
        }

        sort(nails.begin(), nails.end(), [](const Point& a, const Point& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        cout << nails.size() << "\n";
        for (const auto& pt : nails) {
            cout << pt.first << " " << pt.second << " ";
            if (hull_set.find(pt) != hull_set.end()) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}