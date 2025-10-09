#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	vector<char> a1,b1;
	vector<int> idx_aa(n+1,0),idx_ba(n+1,0),idx_ac(n+1,0),idx_bc(n+1,0);
	for(int i=0;i<n;i++){
	    idx_aa[i+1]=idx_aa[i];
	    idx_ba[i+1]=idx_ba[i];
	    idx_ac[i+1]=idx_ac[i];
	    idx_bc[i+1]=idx_bc[i];
		if(a[i]!='b'){
			a1.push_back(a[i]);
			if(a[i]=='a'){
				idx_aa[i+1]++;
			}else{
				idx_ac[i+1]++;
			}
		}
		if(b[i]!='b'){
			b1.push_back(b[i]);
			if(b[i]=='a'){
				idx_ba[i+1]++;
			}else{
				idx_bc[i+1]++;
			}
		}
	}
	if(a1.size()!=b1.size()){
		cout<<"NO\n";
		return;
	}
	for(int i=0;i<a1.size();i++){
		if(a1[i]!=b1[i]){
			cout<<"NO\n";
		    return;
		}
	}
	for(int i=0;i<=n;i++){
		if(idx_aa[i]<idx_ba[i]){
			cout<<"NO\n";
		    return;
		}
		if(idx_ac[i]>idx_bc[i]){
			cout<<"NO\n";
		    return;
		}
	}
	cout<<"YES\n";
}

int main() {
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