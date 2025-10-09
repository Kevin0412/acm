#include<bits/stdc++.h>
using namespace std;

int a[100001],b[100001];

int main(){
	int n,i,j,sum,ans;
	vector<int> c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		if(a[i]<0){
			b[i]=0;
			c.push_back(i);
		}else{
			b[i]=1;
		}
	}
	for(int i:c){
		sum=a[i];
		for(j=i-1;j!=i;j--){
			if(j<0)j=n-1;
			sum+=a[j];
			if(b[j]){
				if(sum>=0){
					break;
				}else{
					b[j]=0;
				}
			}else{
				break;
			}
		}
	}
	ans=0;
	for(i=0;i<n;i++){
		ans+=b[i];
	}
	cout<<ans<<endl;
	return 0;
}