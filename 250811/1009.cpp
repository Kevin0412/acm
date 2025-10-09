#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef __int128_t i128;

struct Group {
    int type;   // 0: single-round group, 1: continuous group
    LL count;
    LL a;       // For continuous group: start round index
    LL key;     // For sorting: for type0, key = survival_round; for type1, key = a + count - 1
};

void print_i128(i128 x) {
    if (x == 0) {
        cout << "0";
        return;
    }
    if (x < 0) {
        cout << "-";
        x = -x;
    }
    string s;
    while (x) {
        s += '0' + (x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        LL n, w;
        cin >> n >> w;
        if (w == 1) {
            i128 ans = (i128)n * (n + 1) / 2;
            print_i128(ans);
            cout << endl;
            continue;
        }

        vector<Group> groups;
        LL s = n;
        LL round_index = 1;

        while (s >= w) {
            if (s >= 2 * w) {
                LL d = s / w;
                groups.push_back({0, d, 0, round_index});
                s -= d;
                round_index++;
            } else {
                LL steps = s - w + 1;
                LL key = round_index + steps - 1;
                groups.push_back({1, steps, round_index, key});
                round_index += steps;
                s = w - 1;
            }
        }
        if (s > 0) {
            groups.push_back({0, s, 0, round_index});
        }

        sort(groups.begin(), groups.end(), [](const Group& a, const Group& b) {
            return a.key > b.key;
        });

        i128 total_ans = 0;
        LL assigned_count = 0;

        for (const Group& g : groups) {
            i128 v = (i128)n - assigned_count;
            if (g.type == 0) {
                i128 count = g.count;
                i128 value_sum = (v + (v - count + 1)) * count / 2;
                total_ans += (i128)g.key * value_sum;
                assigned_count += count;
            } else {
                i128 steps128 = g.count;
                i128 a128 = g.a;
                i128 S1 = (steps128 - 1) * steps128 / 2;
                i128 part1 = (v - steps128 + 1) * (a128 * steps128 + S1);
                i128 S2 = (steps128 - 1) * steps128 * (2 * steps128 - 1) / 6;
                i128 part2 = a128 * S1 + S2;
                total_ans += part1 + part2;
                assigned_count += g.count;
            }
        }

        print_i128(total_ans);
        cout << endl;
    }
    return 0;
}