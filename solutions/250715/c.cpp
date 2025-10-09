#include<bits/stdc++.h>

using namespace std;

int a[1000][1000];

void solve(){
	int i,j,n;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int i=0;i<1000;i++){
		int k=1;
		for(int j=0;j<i+1;j++){
			if(j%2==1){
				a[i][j]=k;
				k++;
			}else{
				a[i][j]=i+1;
			}
		}
		for(int j=0;j<i;j++){
			if(j%2==1){
				a[j][i]=k;
				k++;
			}else{
				a[j][i]=i+1;
			}
		}
	}
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}