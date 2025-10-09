#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,k;
	cin>>n>>k;
	
	long long ai;
	vector<long long> a;
	
	for(int i=0;i<n;i++){
		cin>>ai;
		a.push_back(ai);
	}
	
	sort(a.begin(),a.end());
	auto last=unique(a.begin(),a.end());
	a.erase(last,a.end());
	
	// for(auto i:a){
		// cerr<<i<<" ";
	// }
	
	if(k<=a.size()){
		cout<<a[k-1]<<"\n";
	}else{
		cout<<-1<<"\n";
	}
	
	
	return 0;
}