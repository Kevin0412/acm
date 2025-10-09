#include<bits/stdc++.h>
using namespace std;

int a[500][500];
int main(){
	int i,t;
	int n,x0=249,x1=249,y0=249,y1=249,j,k=0,l=0;
	while(1){
		for(int j=x0;j<=x1;j++){
			a[j][y0]=l;
			l++;
		}
		x1++;
		if(l==250000)break;
		k++;
		for(int j=y0;j<=y1;j++){
			a[x1][j]=l;
			l++;
		}
		y1++;
		if(l==250000)break;
		k++;
		for(int j=x0;j<=x1;j++){
			a[j][y1]=l;
			l++;
		}
		x0--;
		if(l==250000)break;
		k++;
		for(int j=y0;j<=y1;j++){
			a[x0][j]=l;
			l++;
		}
		y0--;
		if(l==250000)break;
		k++;
	}
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n;
		for(j=(500-n)/2;j<(500+n)/2;j++){
			for(k=(500-n)/2;k<(500+n)/2;k++){
				cout<<a[j][k]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}