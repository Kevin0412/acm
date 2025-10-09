#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,s,ai,a[3],i;
    cin>>n>>s;
    for(i=0;i<3;i++){
    	a[i]=0;
    }
    for(i=0;i<n;i++){
    	cin>>ai;
    	a[ai]++;
    }
    int sum=a[1]+2*a[2];
    if(s<sum | s==sum+1){
    	for(i=0;i<a[0];i++){
    		cout<<0<<" ";
    	}
    	for(i=0;i<a[2];i++){
    		cout<<2<<" ";
    	}
    	for(i=0;i<a[1];i++){
    		cout<<1<<" ";
    	}
    	cout<<endl;
    	return;
    }
    cout<<-1<<endl;
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