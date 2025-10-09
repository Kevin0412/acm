#include<bits/stdc++.h>

using namespace std;

int a[1001][1001];
int b[1001][1001];

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int x,y,d,i,x1,x2,y1,y2;
	for(x=0;x<1001;x++){
		for(y=0;y<1001;y++){
			a[x][y]=0;
			b[x][y]=501;
		}
	}
	for(x=0;x<n;x++){
		for(y=0;y<m;y++){
			b[x][y]=0;
		}
	}
	for(i=0;i<k;i++){
		cin>>x>>y>>d;
		x1=x-1-d;
		x2=x+d;
		y1=y-1-d;
		y2=y+d;
		if(x1<0)x1=0;
		if(x2>n)x2=n;
		if(y1<0)y1=0;
		if(y2>m)y2=m;
		a[x1][y1]++;
		a[x2][y1]--;
		a[x1][y2]--;
		a[x2][y2]++;
	}
	for(y=1;y<m;y++){
		a[0][y]+=a[0][y-1];
	}
	for(x=1;x<=n;x++){
		a[x][0]+=a[x-1][0];
		for(y=1;y<=m;y++){
			a[x][y]+=a[x][y-1]+a[x-1][y]-a[x-1][y-1];
		}
	}
	vector<pair<int,int>> c;
	for(x=0;x<n;x++){
		for(y=0;y<m;y++){
			x1=(x-1+1000)%1000;
			x2=x+1;
			y1=(y-1+1000)%1000;
			y2=y+1;
			if(a[x1][y]==0 & a[x2][y]==0 & a[x][y1]==0 & a[x][y2]==0 & a[x][y]==0){
				b[x][y]=1;
				c.push_back({x,y});
			}
		}
	}
	if(c.empty()){
		cout<<-1<<endl;
		return 0;
	}
	i=0;
	while(1){
		x=c[i].first;
		y=c[i].second;
		x1=(x-1+1000)%1000;
		x2=x+1;
		y1=(y-1+1000)%1000;
		y2=y+1;
		if(b[x1][y]>=b[x][y] & b[x2][y]>=b[x][y] & b[x][y1]>=b[x][y] & b[x][y2]>=b[x][y]){
			if((b[x][y]<x | b[x][y]<n-x-1) & (b[x][y]<m-y-1 | b[x][y]<y)){
			    b[x][y]++;
			    c.push_back({x,y});	
			}
		}
		i++;
		if(c.size()==i)break;
	}
	int ans=0;
	for(x=0;x<n;x++){
		for(y=0;y<m;y++){
			ans=max(ans,b[x][y]);
		}
	}
	cout<<ans<<endl;
	return 0;
}