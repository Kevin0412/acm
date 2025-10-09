#include<bits/stdc++.h>

using namespace std;

int main(){
	int i,t,j,n,m,a[200001],b[200001],c,d,e;
	cin>>t;
	for(i=0;i<t;i++){
		std::priority_queue<int> pq;
		c=0;
		cin>>n>>m;
		for(j=0;j<n;j++)cin>>a[j];
		for(j=0;j<n;j++)cin>>b[j];
		for(j=0;j<n;j++){
			pq.push((a[j]+m-b[j])%m);
		}
		d=pq.top();
		pq.pop();
		c=max(m-d,c);
		for(j=0;j<n;j++){
			e=pq.top();
			pq.pop();
			c=max(d-e,c);
			d=e;
		}
		c=max(e,c);
		cout<<m-c<<endl;
	}
	return 0;
}