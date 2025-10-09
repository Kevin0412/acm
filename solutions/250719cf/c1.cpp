#include<bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    int index;
};

int solve() {
    int n,total_points;
    cin >> total_points;
    n=total_points/2;
    
vector<Point> points(total_points);
    for (int i = 0; i < total_points; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].index = i;
    }

    vector<vector<pair<int, int>>> matchings;
    vector<long long> distances;

    vector<Point> sorted_x = points;
    sort(sorted_x.begin(), sorted_x.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });
    vector<pair<int, int>> m1;
    long long dist1 = 0;
    for (int i = 0; i < n; i++) {
        int idx1 = sorted_x[i].index;
        int idx2 = sorted_x[total_points - 1 - i].index;
        m1.push_back({min(idx1, idx2), max(idx1, idx2)});
        dist1 += abs(points[idx1].x - points[idx2].x) + abs(points[idx1].y - points[idx2].y);
    }
    matchings.push_back(m1);
    distances.push_back(dist1);

    vector<pair<int, int>> m2;
    long long dist2 = 0;
    for (int i = 0; i < n; i++) {
        int idx1 = sorted_x[i].index;
        int idx2 = sorted_x[i + n].index;
        m2.push_back({min(idx1, idx2), max(idx1, idx2)});
        dist2 += abs(points[idx1].x - points[idx2].x) + abs(points[idx1].y - points[idx2].y);
    }
    matchings.push_back(m2);
    distances.push_back(dist2);

    vector<Point> sorted_y = points;
    sort(sorted_y.begin(), sorted_y.end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
    });
    vector<pair<int, int>> m3;
    long long dist3 = 0;
    for (int i = 0; i < n; i++) {
        int idx1 = sorted_y[i].index;
        int idx2 = sorted_y[total_points - 1 - i].index;
        m3.push_back({min(idx1, idx2), max(idx1, idx2)});
        dist3 += abs(points[idx1].x - points[idx2].x) + abs(points[idx1].y - points[idx2].y);
    }
    matchings.push_back(m3);
    distances.push_back(dist3);

    vector<pair<int, int>> m4;
    long long dist4 = 0;
    for (int i = 0; i < n; i++) {
        int idx1 = sorted_y[i].index;
        int idx2 = sorted_y[i + n].index;
        m4.push_back({min(idx1, idx2), max(idx1, idx2)});
        dist4 += abs(points[idx1].x - points[idx2].x) + abs(points[idx1].y - points[idx2].y);
    }
    matchings.push_back(m4);
    distances.push_back(dist4);

    auto transform = [](int type, const Point& p) -> long long {
        if (type == 0) return p.x + p.y;
        if (type == 1) return p.x - p.y;
        if (type == 2) return -p.x + p.y;
        return -p.x - p.y;
    };

    for (int t = 0; t < 4; t++) {
        vector<Point> sorted = points;
        sort(sorted.begin(), sorted.end(), [&](const Point& a, const Point& b) {
            return transform(t, a) < transform(t, b);
        });
        vector<pair<int, int>> m;
        long long dist = 0;
        for (int i = 0; i < total_points; i += 2) {
            int idx1 = sorted[i].index;
            int idx2 = sorted[i+1].index;
            m.push_back({min(idx1, idx2), max(idx1, idx2)});
            dist += abs(points[idx1].x - points[idx2].x) + abs(points[idx1].y - points[idx2].y);
        }
        matchings.push_back(m);
        distances.push_back(dist);
    }

    int best_index = 0;
    long long max_dist = distances[0];
    for (int i = 1; i < 8; i++) {
        if (distances[i] > max_dist) {
            max_dist = distances[i];
            best_index = i;
        }
    }

    auto& best_matching = matchings[best_index];
    for (auto& edge : best_matching) {
        cout << edge.first+1 << " " << edge.second+1 << '\n';
    }
    return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}