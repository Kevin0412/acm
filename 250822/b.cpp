#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i,n;
	string a,b;
	cin>>n>>a>>b;
	vector<int> diff;
	for(i=0;i<n;i++){
		if(a[i]!=b[i]){
			diff.push_back(i);
		}
	}
	if(diff.size()%2==1){
		cout<<-1<<"\n";
		return 0;
	}
	int diff1=0,diff2=0;
	vector<int> ans;
	for(i=0;i<n;i++){
		ans.push_back(0);
	}
	for(auto i:diff){
		if(diff1*2<diff.size() & diff2*2<diff.size()){
			if(a[i]=='0'){
				diff2++;
			}else{
				diff1++;
			}
		}else if(diff1*2==diff.size()){
			if(a[i]=='1'){
				ans[i]=1;
			}
		}else{
			if(b[i]=='1'){
				ans[i]=1;
			}
		}
	}
	for(auto i:ans){
		cout<<i;
	}
	cout<<"\n";
	return 0;
}