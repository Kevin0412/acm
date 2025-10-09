#include<bits/stdc++.h>

using namespace std;

long long a[100001],b[100001];

void solve(){
	int n,i,j,ans,k;
	long long c=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		b[i]=0;
		c|=a[i];
	}
	j=0;ans=0;k=1;
	while(1){
		while(a[j]==c | b[j]==c){
			j++;
			if(j==n){
				break;
			}
		}
		if(j==n){
			break;
		}
		ans++;
		if(k%2==1){
			for(i=0;i<n;i++){
				b[i]=a[i]|a[(i+k)%n];
			}
		}else{
			for(i=0;i<n;i++){
				a[i]=b[i]|b[(i+k)%n];
			}
		}
		k++;
	}
	cout<<ans<<endl;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}