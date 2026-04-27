#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[3005];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T-->0){
        ll n,k;
        cin >> n >> k;
        for(ll i=0;i<n;i++) cin >> a[i];

        sort(a,a+n);
        reverse(a,a+n);

        ll cnt=1,p=0,t=k-1,ans=1;
        a[0]--;
        while(cnt<n){
            if(a[p]>t){
                a[p]-=t;
                ans+=t;
                cnt++;
                t=k;
            }else{
                t-=a[p];
                ans+=a[p];
                a[p]=0;
                p++;
                cnt++;
                cout << "qwq" << endl;
            }
            cout << "cnt=" << cnt << " p=" << p << " t=" << t << " ans=" << ans << "\n";
        }

        cout << ans << "\n";
    }

    return 0;
}