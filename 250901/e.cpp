#include<bits/stdc++.h>

using namespace std;

long long f;

struct p{
	long long l;
	long long r;
	int i;
	bool operator<(const p& other) const {
		if(l==other.l){
			if(r==other.r)return i<other.i;
			return r<other.r;
		}
	    return l < other.l;
	}
    // bool operator<(const p& other) const {
		// if(r==other.r){
			// if(l==other.l)return i>other.i;
			// return l<other.l;
		// }
	    // return r > other.r;
	// }
};

bool cmp(const p& a, const p& b) {
    if(a.r==b.r){
		if(a.l==b.l)return a.i>b.i;
		return a.l<b.l;
	}
	return a.r > b.r;
}

void solve(){
	int n;
	cin>>n>>f;
	vector<p> a;
	long long l,r;
	for(int i=1;i<=n;i++){
		cin>>l>>r;
		a.push_back({l,r,i});
	}
	sort(a.begin(),a.end());
	vector<tuple<long long,long long,int>> b;
	b.push_back({a[0].l,a[0].r,0});
	for(int i=1;i<n;i++){
		if(a[i].l>get<1>(b.back())){
			b.push_back({a[i].l,a[i].r,i});
		}else{
			get<1>(b.back())=max(get<1>(b.back()),a[i].r);
		}
	}
	vector<p> ans;
	long long ans1=0;
	unordered_set<int> s;
	for(auto j:b){
		if(get<1>(j)>=f){
		    int i=get<2>(j);
		    ans.push_back(a[i]);
		    s.insert(a[i].i);
		    long long h=a[i].r;
		    while(1){
		    	if(h==get<1>(j))break;
		    	i++;
		    	if(a[i].l<=h & a[i].r>h){
		    		ans.push_back(a[i]);
				    s.insert(a[i].i);
				    h=a[i].r;
		    	}
		    }
		}
	}
	vector<p> a1;
	for (auto element : a) {
        if (s.find(element.i) == s.end()) {
            a1.push_back(element);
        }
    }
    sort(a1.begin(),a1.end(),cmp);
    
    for(auto i:a1){ans.push_back(i);}
	
	ans1=max(ans[0].l-f,0LL)+ans[0].r-ans[0].l;
	for(int i=1;i<n;i++){
		ans1+=max(ans[i].l-ans[i-1].r,0LL)+ans[i].r-ans[i].l;
	}
	cout<<ans1<<"\n";
	for(int i=0;i<n;i++){
		cout<<ans[i].i<<" ";
	}
	cout<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}