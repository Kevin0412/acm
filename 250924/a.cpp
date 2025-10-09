#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(m);
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	vector<int> mins,maxs;
	mins.push_back(a[0]);
	for(int i=0;i<m-1;i++){
		if(a[i+1]-a[i]!=1){
			maxs.push_back(a[i]);
			mins.push_back(a[i+1]);
		}else{
			if(i==m-2){
				maxs.push_back(a[m-1]);
			}
		}
	}
	if(maxs.size()!=mins.size()){
		maxs.push_back(a[m-1]);
	}
	//for(auto i:mins){
		//cerr<<i<<" ";
	//}
	//cerr<<"\n";
	//for(auto i:maxs){
		//cerr<<i<<" ";
	//}
	//cerr<<"\n";
	for(int i=1;i<mins.size();i++){
		if(i<mins.size())break;
		if(mins[i]!=1){
			cout<<"0\n";
			return;
		}
	}
	int maxa=maxs[0];
	//cerr<<maxa<<" "<<maxs.size()<<"\n";
	for(int i=0;i<maxs.size()-2;i++){
		if(i<maxs.size()-2)break;
		if(maxs[i+1]-maxs[i]!=1){
			cout<<"0\n";
			return;
		}
		maxa=max(maxa,maxs[i+1]);
	}
	if(maxs.size()>1)maxa++;
	//cerr<<maxa<<"\n";
	if(maxs.size()>1){
		cout<<"1\n";
		return;
	}
	cout<<n-maxa+1<<"\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		//cerr<<t<<":\n";
		solve();
	}
	return 0;
}