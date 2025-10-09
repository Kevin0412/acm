#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	char a[200001];
	int b[200001];
	cin>>a;
	int sum,i;
	for(i=0;i<n;i++){
		if(a[i]=='1'){
			sum++;
		}
	}
	if(sum==0 | sum==n){
		cout<<-1<<endl;
		return 0;
	}
	int j=0,k=n-1,l;
	if(a[0]!=a[n-1]){
		for(i=0;i<n;i++){
			if(a[i]=='1'){
				b[i]=k;
				k--;
			}else{
				b[i]=j;
				j++;
			}
		}
	}else{
		if(a[0]=='0'){
			for(i=0;i<n;i++){
				if(a[i]=='1'){
					b[i]=k;
					l=i;
					k--;
				}
			}
			for(i=0;i<n;i++){
				if(a[(l+i)%n]=='0'){
					b[(l+i)%n]=j;
					j++;
				}
			}
		}else{
			for(i=0;i<n;i++){
				if(a[i]=='0'){
					b[i]=j;
					l=i;
					j++;
				}
			}
			for(i=0;i<n;i++){
				if(a[(l+i)%n]=='1'){
					b[(l+i)%n]=k;
					k--;
				}
			}
		}
	}
	for(i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	return 0;
}