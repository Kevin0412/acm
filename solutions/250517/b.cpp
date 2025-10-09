#include<bits/stdc++.h>
using namespace std;

int main(){
	int i,t,m,n,a,b,m1,n1,ans1,ans2;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n>>m>>a>>b;
		ans1=0;
		if(a*2>n){
			n1=n-a+1;
		}else{
			n1=a;
		}
		m1=m;
		if(n!=n1){
			ans1++;
		}
		while(m1!=1){
			m1+=m1%2;
			m1/=2;
			ans1++;
		}
		while(n1!=1){
			n1+=n1%2;
			n1/=2;
			ans1++;
		}
		ans2=0;
		if(b*2>m){
			m1=m-b+1;
		}else{
			m1=b;
		}
		n1=n;
		if(m!=m1){
			ans2++;
		}
		while(m1!=1){
			m1+=m1%2;
			m1/=2;
			ans2++;
		}
		while(n1!=1){
			n1+=n1%2;
			n1/=2;
			ans2++;
		}
		cout<<min(ans1,ans2)<<endl;
	}
	return 0;
}