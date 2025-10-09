#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;

    unordered_set<string> unique_strings;
    for (int i = 0; i < n;i++) {
        string s;
        cin >> s;
        unique_strings.insert(move(s));
    }

    cout << unique_strings.size() << endl;
    return 0;
}