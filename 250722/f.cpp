#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, a;
    long long b;
    cin >> n >> a >> b;

    int s;
    cin >> s;

    vector<bool> solved(26, false);
    vector<int> base_fail(26, 0);
    vector<int> min_pending_time(26, INT_MAX);

    int m0 = 0;
    long long penalty0 = 0;

    for (int i = 0; i < s; i++) {
        int t;
        string p_str, v;
        cin >> t >> p_str >> v;
        char p_char = p_str[0];
        int idx = p_char - 'A';

        if (v == "ac") {
            if (!solved[idx]) {
                solved[idx] = true;
                m0++;
                penalty0 += t + 20LL * base_fail[idx];
            }
        } else if (v == "rj") {
            if (!solved[idx]) {
                base_fail[idx]++;
            }
        } else if (v == "pd") {
            if (!solved[idx]) {
                min_pending_time[idx] = min(min_pending_time[idx], t);
            }
        }
    }

    vector<long long> available;
    for (int idx = 0; idx < 26; idx++) {
        if (!solved[idx] && min_pending_time[idx] != INT_MAX) {
            long long penalty_i = min_pending_time[idx] + 20LL * base_fail[idx];
            available.push_back(penalty_i);
        }
    }

    sort(available.begin(), available.end());
    vector<long long> prefix(available.size() + 1, 0);
    for (int i = 0; i < available.size(); i++) {
        prefix[i + 1] = prefix[i] + available[i];
    }

    int ans = -1;
    for (int k = 0; k <= available.size(); k++) {
        int total_solved = m0 + k;
        long long total_penalty = penalty0 + prefix[k];

        if (total_solved > a || (total_solved == a && total_penalty < b)) {
            ans = k;
            break;
        }
    }

    if (ans == -1) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}