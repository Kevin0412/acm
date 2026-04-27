#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int a,b;
    cin >> a >> b;
    if(a>=30 || (a>=21 && a-b>=2)){
        cout << "Alice\n";
    }else if(b>=30 || (b>=21 && b-a>=2)){
        cout << "Bob\n";
    }else{
        cout << "Underway\n";
    }

    return 0;
}