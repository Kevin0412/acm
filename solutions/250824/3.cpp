#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	long long m;
	cin>>n>>m;
	
	long long ai;
	vector<long long> a;
	
	for(int i=0;i<n;i++){
		cin>>ai;
		a.push_back(ai);
	}
	
	long long ansl=1,ansr=1000000001;
	long long sum=0,ans;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	if(sum<=m){
		cout<<1<<"\n";
		return;
	}
	while(true){
		ans=(ansl+ansr)/2;
		sum=0;
		for(int i=0;i<n;i++){
			sum+=a[i]/ans;
		}
		if(sum>m){
			ansl=ans;
		}else{
			ansr=ans;
		}
		if(ansr-ansl==1){
			break;
		}
	}
	cout<<ansr<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    int t;
    cin>>t;
    while(t--)solve();
	
	return 0;
}