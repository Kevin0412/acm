#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	vector<int> sa[3],sb[3];
	for(int i=0;i<n;i++){
		sa[a[i]-'a'].push_back(i);
		sb[b[i]-'a'].push_back(i);
	}
	for(int i=0;i<3;i++){
		if(sa[i].empty() & sb[i].empty()){
			cout<<"YES\n1\n"<<(char)('a'+i)<<endl;
			return;
		}
	}
	for(int i=0;i<3;i++){
		if(sa[i].size()==sb[i].size()){
			if(sa[i]==sb[i]){
				cout<<"YES\n1\n"<<(char)('a'+i)<<endl;
			    return;
			}
		}
	}
	cout<<"NO"<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}