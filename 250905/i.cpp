#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	if(k<n | k>n*n-n+1){
		cout<<"No\n";
		return;
	}
	vector<vector<int>> a(n,vector<int>(n));
	a[0][0]=k;
	int b=n*n;
	if(k==n*n)b--;
	for(int i=1;i<n;i++){
		a[i][i]=b;
		b--;
	}
	for(int i=1;i<n;i++){
		a[i][0]=i;
		if(i+n-1>=k) a[0][i]=i+n;
		else a[0][i]=i+n-1;
	}
	int i=2*n-1;
	if(k<2*n-1){
		i++;
	}
	for(int x=1;x<n;x++){
		for(int y=1;y<n;y++){
		    if(x!=y){
		    	if(k!=i)a[x][y]=i;
				else{
					i++;
					a[x][y]=i;
				}
				i++;
		    }
		}
	}
	cout<<"Yes\n";
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cout<<a[x][y]<<" ";
		}
		cout<<"\n";
	}
}

int main(){
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