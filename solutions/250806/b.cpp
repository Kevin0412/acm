#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, b, d;
    cin >> n >> b >> d;
    vector<int> ans;
    int max_val = (1 << b) - 1;
    for (int i = 0; i <= max_val; i++) {
        if (ans.size() == n) 
            break;
        bool valid = true;
        for (int num : ans) {
            int diff = i ^ num;
            int dist = __builtin_popcount(diff);
            if (dist < d) {
                valid = false;
                break;
            }
        }
        if (valid) {
            ans.push_back(i);
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i % 10 == 9) {
            cout << endl;
        } else {
            if (i != ans.size() - 1) {
                cout << " ";
            }
        }
    }
    if (ans.size() % 10 != 0) {
        cout << endl;
    }
    return 0;
}