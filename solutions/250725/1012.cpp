#include <bits/stdc++.h>
using namespace std;

long long MOD=1000000007;

inline long long read() {
    long long x = 0;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x;
}

struct {
	long long x,y,a;
} core[200005];

void solve() {
    int n=read();
    for(int i=0;i<n;i++){
    	scanf("%lld %lld %lld",&(core[i].x),&(core[i].y),&(core[i].a));
    }
    vector<tuple<long long,int>> xs,ys;
    for(int i=0;i<n;i++){
    	xs.push_back({core[i].x+core[i].y,i});
    	ys.push_back({-core[i].x+core[i].y,i});
    }
    sort(xs.begin(),xs.end());
    sort(ys.begin(),ys.end());
    vector<long long> sxs,sys;
    long long sumx=0,sumy=0;
    sxs.push_back(sumx);
    sys.push_back(sumy);
    for(int i=0;i<n;i++){
    	//cerr<<get<0>(xs[i])<<" "<<get<0>(ys[i])<<endl;
    	sumx+=(get<0>(xs[i])+2*MOD)%(2*MOD);
    	sumy+=(get<0>(ys[i])+2*MOD)%(2*MOD);
    	//cerr<<sumx<<" "<<sumy<<endl;
    	sumx%=2*MOD;
    	sumy%=2*MOD;
    	//cerr<<sumx<<" "<<sumy<<endl;
    	sxs.push_back(sumx);
    	sys.push_back(sumy);
    }
    vector<long long> xa(n),ya(n);
    long long xi,yi;
    for(int i=0;i<n;i++){
    	xi=(2*i-n)*get<0>(xs[i])+sxs[n]-2*sxs[i];
    	yi=(2*i-n)*get<0>(ys[i])+sys[n]-2*sys[i];
    	xi=(xi+(n+2)*2*MOD)%(2*MOD);
    	yi=(yi+(n+2)*2*MOD)%(2*MOD);
    	xa[get<1>(xs[i])]=xi;
    	ya[get<1>(ys[i])]=yi;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
    	ans+=core[i].a*((xa[i]+ya[i])/2);
    	ans%=MOD;
    }
    cout<<ans<<endl;
}

int main() {
    int t = read();
    while (t--) {
        solve();
    }
    return 0;
}