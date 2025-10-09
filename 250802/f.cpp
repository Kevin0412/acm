#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        double r0, c0, p, L, R;
        cin >> r0 >> c0 >> p >> L >> R;

        vector<pair<int, double>> fixed_days;
        for (int i = 0; i < k; i++) {
            int day;
            double v;
            cin >> day >> v;
            fixed_days.push_back({day, v});
        }

        double pn = pow(p, n);
        double A = c0 * (p * (1.0 - pn) / (1.0 - p)) + r0 * (1.0 - pn);
        double total_all_weights = (1.0 - pn) / (1.0 - p);

        double fixed_weights_sum = 0.0;
        double B_fixed = 0.0;
        for (auto &dv : fixed_days) {
            int day_index = dv.first;
            double value = dv.second;
            double exponent = n - day_index;
            double weight = pow(p, exponent);
            fixed_weights_sum += weight;
            B_fixed += weight * value;
        }

        double free_weights_sum = total_all_weights - fixed_weights_sum;
        double B = B_fixed + L * free_weights_sum;
        double S = A - B;

        cout << fixed << setprecision(10) << S << '\n';
    }
    return 0;
}