#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (k == 0) {
        for (int i = 0; i < n; i++) {
            cout << '4';
        }
        cout << endl;
    } else if (k == n) {
        if (n % 4 == 0) {
            int blocks = n / 4;
            for (int i = 0; i < blocks; i++) {
                cout << "1234";
            }
            cout << endl;
        } else if (n % 2 == 0) {
            int pairs = n / 2;
            for (int i = 0; i < pairs; i++) {
                cout << "24";
            }
            cout << endl;
        } else {
            cout << '1';
            int pairs = (n - 1) / 2;
            for (int i = 0; i < pairs; i++) {
                cout << "24";
            }
            cout << endl;
        }
    } else {
        for (int i = 0; i < k; i++) {
            cout << '1';
        }
        for (int i = 0; i < n - k; i++) {
            cout << '4';
        }
        cout << endl;
    }

    return 0;
}