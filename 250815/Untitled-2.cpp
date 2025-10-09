#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 快读模板
template <typename T>
void read(T &x) {
    x = 0;
    T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> diffs;
    int T;
    read(T);
    while (T--) {
        int n, m;
        read(n);read(m);
        vector<int> records(m);
        for (int i = 0; i < m; i++) {
            read(records[i]);
        }

        unordered_map<int, int> count_map;
        unordered_map<int, int> first_time_map;

        for (int i = 0; i < m; i++) {
            int p = records[i];
            count_map[p]++;
            if (first_time_map.find(p) == first_time_map.end()) {
                first_time_map[p] = i;
            }
        }

        vector<int> problems;
        for (const auto& kv : count_map) {
            problems.push_back(kv.first);
        }
        int k = problems.size();

        vector<pair<int, int>> list1;
        for (int p : problems) {
            list1.push_back(make_pair(count_map[p], p));
        }
        sort(list1.begin(), list1.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });

        vector<pair<int, int>> list2;
        for (int p : problems) {
            list2.push_back(make_pair(first_time_map[p], p));
        }
        sort(list2.begin(), list2.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });

        int diff = 0;
        for (int i = 0; i < k; i++) {
            if (list1[i].second != list2[i].second) {
                diff++;
            }
        }
        diffs.push_back(diff);
    }
    for(auto i:diffs){
    	printf("%d\n",i);
    }
    return 0;
}