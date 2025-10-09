#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n,m;
	unordered_set<int> b;
	cin>>n>>m;
	string s;
	cin>>s;
	int a;
	for(int i=0;i<m;i++){
		cin>>a;
		b.insert(a);
	}
	vector<int> ans;
	int k=1;
	for(int i=0;i<n;i++){
		// if(b.find(k) != b.end()){
			// ans.push_back(k);
		// }
		if(s[i]=='A'){
			k++;
			b.insert(k);
		}else{
			while(1){
				k++;
				if(b.find(k) == b.end()){
					break;
				}
			}
			b.insert(k);
			while(1){
				k++;
				if(b.find(k) == b.end()){
					break;
				}
			}
		}
	}
	for(auto i:b){
		ans.push_back(i);
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<"\n";
	for(auto i:ans){
		cout<<i<<" ";
	}
	cout<<"\n";
}

signed main(){
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