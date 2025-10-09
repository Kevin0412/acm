#include<bits/stdc++.h>

using namespace std;

int main(){
	int i,n,m,d,m1,d1,m2,d2;
	int a[10001];
	int b[10001];
	cin>>n>>m>>d;
	for(i=0;i<m*d+1;i++){
		a[i]=0;
		b[i]=0;
	}
	for(i=0;i<n;i++){
		cin>>m1>>d1>>m2>>d2;
		a[(m1-1)*d+d1-1]++;
		a[(m2-1)*d+d2]--;
	}
	b[0]=a[0];
	for(i=1;i<m*d+1;i++){
		b[i]=b[i-1]+a[i];
	}
	for(i=0;i<m*d;i++){
		if(b[i]==0){
			cout<<(i+1)/d+1<<" "<<i%d+1<<endl;
			return 0;
		}
	}
	cout<<"Online"<<endl;
	return 0;
}