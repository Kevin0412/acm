#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,j;
	double a[100001];
	a[0]=0.0;
	for(int i=1;i<=100000;i++){
		a[i]=(a[i-1]-1)*(((double)i-1)/(double)i)+a[i-1]/(double)i+1;
	}
	cin>>t;
	while(t--){
		cin>>j;
		printf("%.15lf\n",a[j]);
	}
	return 0;
}