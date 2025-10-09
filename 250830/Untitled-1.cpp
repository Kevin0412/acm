#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a,b,c;
    cin>>a>>b>>c;
    cout<<100<<endl;
    for(int i=1;i<=50;++i) {
        cout<<a<<" ";
    }
    for(int i=1;i<=45;++i) {
        cout<<b<<" ";
    }
    for(int i=1;i<=4;++i) {
        cout<<c<<" ";
    }
    cout<<c+1;

    return 0;
}