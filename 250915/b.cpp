#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int zeros=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			zeros++;
			if(zeros>=2){break;}
		}
	}
	if(zeros==1){
		vector<int> b(n+1,0);
		int idx;
		for(int i=1;i<=n;i++){
			if(a[i]!=0){
				b[a[i]]++;
			}else{
				idx=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(!b[i]){
				a[idx]=i;
				break;
			}
		}
	}
	// for(int i=1;i<=n;i++){
		// cerr<<a[i]<<" ";
	// }
	// cerr<<"\n";
	vector<int> c(n+1,0);
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			c[i]=1;
		}
	}
	int l=0,r=0;
	for(int i=1;i<=n;i++){
		if(c[i]){
			if(l==0){
				l=i;
			}
			r=i;
		}
	}
	if(r==l){
		cout<<"0\n";
		return;
	}
	cout<<r-l+1<<"\n";
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