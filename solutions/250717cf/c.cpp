#include<bits/stdc++.h>

using namespace std;

void solve(){
	int i,n,k,h0;
	vector<int> h;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>h0;
		h.push_back(h0);
	}
	if(n<=1){
		cout<<"YES"<<endl;
		return;
	}
	h0=h[k-1];
	sort(h.begin(),h.end());
	int w=1;
	i=0;
	if(h0==h[n-1]){
		cout<<"YES"<<endl;
		return;
	}
	while(1){
		while(h[i]<=h0)i++;
		w+=h[i]-h0-1;
		cerr<<w<<" "<<h0<<endl;
		if(h0<w){
			cout<<"NO"<<endl;
			return;
		}
		h0=h[i];
		w++;
		cerr<<w<<" "<<h0<<endl;
		if(h0==h[n-1]){
			cout<<"YES"<<endl;
			return;
		}
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
