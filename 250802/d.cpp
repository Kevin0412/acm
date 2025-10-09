#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long compute_max_overlap(vector<pair<long long, int>> &events) {
    if (events.empty()) 
        return 0;
    sort(events.begin(), events.end());
    long long current = 0;
    long long best = 0;
    for (int i = 0; i < events.size(); ) {
        long long x = events[i].first;
        long long delta = 0;
        while (i < events.size() && events[i].first == x) {
            delta += events[i].second;
            i++;
        }
        current += delta;
        if (current > best) 
            best = current;
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long a, b, c;
    cin >> n >> a >> b >> c;

    vector<long long> x1(n), y1(n), z1(n), x2(n), y2(n), z2(n);
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> z1[i] >> x2[i] >> y2[i] >> z2[i];
    }

    vector<pair<long long, int>> events_x, events_y, events_z;

    for (int i = 0; i < n; i++) {
        long long low_x = min(x1[i], x2[i]);
        long long high_x = max(x1[i], x2[i]);
        events_x.push_back({low_x, 1});
        events_x.push_back({high_x + 1, -1});

        long long low_y = min(y1[i], y2[i]);
        long long high_y = max(y1[i], y2[i]);
        events_y.push_back({low_y, 1});
        events_y.push_back({high_y + 1, -1});

        long long low_z = min(z1[i], z2[i]);
        long long high_z = max(z1[i], z2[i]);
        events_z.push_back({low_z, 1});
        events_z.push_back({high_z + 1, -1});
    }

    long long max_x = compute_max_overlap(events_x);
    long long max_y = compute_max_overlap(events_y);
    long long max_z = compute_max_overlap(events_z);

    long long ans = max({max_x, max_y, max_z});
    cout << ans << endl;

    return 0;
}