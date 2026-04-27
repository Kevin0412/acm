#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,q;
	long long ai;
	vector<long long> a;
	
	cin>>n>>q;
	
	for(int i=0;i<n;i++){
	    cin>>ai;
	    a.push_back(ai);
	}
	
	int opt,k;
	long long v;
	for(int i=0;i<q;i++){
		cin>>opt>>k>>v;
		if(opt==1){
			a[k-1]+=v;
		}else{
			a[k-1]-=v;
		}
	}
	
	for(auto i:a){
		cout<<i<<" ";
	}
	
	cout<<"\n";
	
	return 0;
}