#include<bits/stdc++.h>

using namespace std;

int main(){
	int i,n,m,s=1,j;
	double re,im,p[256],p0,p1;
	cin>>n;
	m=1;
	for(i=0;i<n;i++){
		m*=2;
	}
	for(i=0;i<m;i++){
		cin>>re>>im;
		p[i]=re*re+im*im;
	}
	for(i=0;i<n;i++){
		p0=0;
		p1=0;
		for(j=0;j<m;j++){
			if((j/s)%2){
				p1+=p[j];
			}else{
				p0+=p[j];
			}
		}
		printf("%.9lf %.9lf\n",p0,p1);
		s*=2;
	}
	return 0;
}