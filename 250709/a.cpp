#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,i,ans=0,x,y;
	vector<pair<int,int>> a;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x>>y;
		a.push_back({x,y});
	}
	a.push_back(a[0]);
	for(i=0;i<n;i++){
		ans+=a[i].first*a[i+1].second-a[i].second*a[i+1].first;
	}
	cout<<abs(ans/2)<<endl;
	return 0;
}