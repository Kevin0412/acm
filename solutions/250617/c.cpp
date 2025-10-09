#include<bits/stdc++.h>

using namespace std;

int main(){
	int i,j,t,n,m,a[100001],maxa,c1=-1,r1=-1,ans,flag;
	vector<int> c,r;
	cin>>t;
	for(i=0;i<t;i++){
		c.clear();
		r.clear();
		c1=-1;
		r1=-1;
		cin>>n>>m;
		maxa=0;
		for(j=0;j<n*m;j++){
			cin>>a[j];
			maxa=max(a[j],maxa);
		}
		for(j=0;j<n*m;j++){
			if(maxa==a[j]){
				c.push_back(j%m);
				r.push_back(j/m);
				//cerr<<i<<" "<<maxa<<" "<<j%m<<" "<<j/m<<endl;
			}
		}
		c1=c[0];
		flag=1;
		for(j=1;j<c.size();j++){
			if(c[j]!=c[0]){
				if(r1!=-1){
					if(r1!=r[j]){
						flag=0;
						break;
					}
				}else{
					r1=r[j];
				}
			}
		}
		if(flag){
			cout<<maxa-1<<endl;
			continue;
		}
		c1=-1;
		r1=r[0];
		flag=1;
		for(j=1;j<c.size();j++){
			if(r[j]!=r[0]){
				if(c1!=-1){
					if(c1!=c[j]){
						flag=0;
						break;
					}
				}else{
					c1=c[j];
				}
			}
		}
		if(flag){
			cout<<maxa-1<<endl;
			continue;
		}
		cout<<maxa<<endl;
	}
	return 0;
}