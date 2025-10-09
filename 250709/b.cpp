#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

int main() {
    int n, r;
    cin >> n >> r;
    vector<pair<double, double>> a;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }

    for (int i = 0; i < n; i++) {
        if (abs(a[i].second) > r) {
            cout << -1 << endl;
            return 0;
        }
    }

    auto leftLimit = [r](const pair<double, double>& p) -> double {
        return p.first - sqrt(r*r - p.second*p.second);
    };
    auto rightLimit = [r](const pair<double, double>& p) -> double {
        return p.first + sqrt(r*r - p.second*p.second);
    };

    sort(a.begin(), a.end(), [&](const pair<double, double>& x, const pair<double, double>& y) {
        return rightLimit(x) < rightLimit(y);
    });

    double last = -1e18;
    int count = 0;
    for (int i = 0; i < n; i++) {
        double L = leftLimit(a[i]);
        if (last < L - eps) {
            count++;
            last = rightLimit(a[i]);
        }
    }

    cout << count << endl;
    return 0;
}