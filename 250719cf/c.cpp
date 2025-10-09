#include<bits/stdc++.h>

using namespace std;

struct point{
	int x,y,no;
};

int dis(point a,point b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}

int dis2(point a,point b){
	return min(abs(a.x-a.y-b.x+b.y),abs(a.x+a.y-b.x-b.y));
}

void solve(){
	int i,n,x,y;
	vector<point> p1,p2;
	vector<int> visited;
	cin>>n;
    for(i=1;i<=n;i++){
    	cin>>x>>y;
    	p1.push_back({x,y,i});
    	p2.push_back({x,y,i});
    	visited.push_back(0);
    }
    int l1=0,r1=n-1,l2=0,r2=n-1;
    sort(p1.begin(),p1.end(),[](auto a,auto b){return a.x+a.y<b.x+b.y;});
    sort(p2.begin(),p2.end(),[](auto a,auto b){return a.x-a.y<b.x-b.y;});
    for(i=0;i<n/2;i++){
    	if(dis(p1[l1],p1[r1])>dis(p2[l2],p2[r2])){
    		cout<<p1[l1].no<<" "<<p1[r1].no<<endl;
    		visited[p1[l1].no-1]=1;
    		visited[p1[r1].no-1]=1;
    	}else if(dis(p1[l1],p1[r1])<dis(p2[l2],p2[r2])){
    		cout<<p2[l2].no<<" "<<p2[r2].no<<endl;
    		visited[p2[l2].no-1]=1;
    		visited[p2[r2].no-1]=1;
    	}else if(dis(p1[l1],p1[r1])<dis(p2[l2],p2[r2])){
    		cout<<p1[l1].no<<" "<<p1[r1].no<<endl;
    		visited[p1[l1].no-1]=1;
    		visited[p1[r1].no-1]=1;
    	}else{
    		cout<<p2[l2].no<<" "<<p2[r2].no<<endl;
    		visited[p2[l2].no-1]=1;
    		visited[p2[r2].no-1]=1;
    	}
    	while(visited[p1[l1].no-1])l1++;
    	while(visited[p1[r1].no-1])r1--;
    	while(visited[p2[l2].no-1])l2++;
    	while(visited[p2[r2].no-1])r2--;
    }
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}