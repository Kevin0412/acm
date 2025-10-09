#include<bits/stdc++.h>

using namespace std;

int main(){
	int i,j,t,n,s,x,maxx,minx;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n>>s;
		cin>>x;
		maxx=x;
		minx=x;
		for(j=1;j<n;j++){
			cin>>x;
			maxx=max(x,maxx);
			minx=min(x,minx);
		}
		cout<<min(abs(s-minx),abs(maxx-s))+maxx-minx<<endl;
	}
	return 0;
}