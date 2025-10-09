#include<bits/stdc++.h>

using namespace std;

struct casino {int l,r,real,visited;};

void solve(){
	int n,k,i,l,r,real;
	vector<casino> c;
	vector<int> avail;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>l>>r>>real;
		c.push_back({l,r,real,0});
	}
	sort(c.begin(),c.end(),[](casino a,casino b){return a.real<b.real;});
	while(1){
		avail.clear();
		for(i=0;i<n;i++){
			if(c[i].l<=k & c[i].r>=k & !c[i].visited){
				avail.push_back(c[i].real);
				c[i].visited=1;
			}
		}
		if(avail.empty()){
			cout<<k<<endl;
			return;
		}
		k=avail[avail.size()-1];
	}
}

int main(){
    int T;
    cin>>T;
    while(T--){
	solve();
    }
    return 0;
}
