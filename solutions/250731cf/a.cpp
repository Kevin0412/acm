#include<bits/stdc++.h>

using namespace std;

int a[51];

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
    	if(a[i]==0){
    		sum=sum+1;
    	}
    	sum=sum+a[i];
    }
    cout<<sum<<endl;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}