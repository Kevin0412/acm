#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int> tree[],vector<int> &c,vector<int> a,vector<int> &d,int u,int v){
	int i;
	for(i=0;i<(tree[u]).size();i+=2){
		if(tree[u][i]!=v){
			if(-d[u-1]-a[u-1]+tree[u][i+1]>0)c[tree[u][i]-1]=c[u-1]-a[u-1]+tree[u][i+1]-d[u-1];
			else{
				c[tree[u][i]-1]=c[u-1];
				d[tree[u][i]-1]=d[u-1]+a[u-1]-tree[u][i+1];
			}
		    dfs(tree,c,a,d,tree[u][i],u);
		}
	}
}

int main(){
	int i,t,j,n,b,u,v,w,minu,minv;
	cin>>t;
	vector<int> tree[200001],c,a,d,e;
	for(i=0;i<t;i++){
		c.clear();
		c.push_back(0);
		a.clear();
		a.push_back(0);
		d.clear();
		d.push_back(0);
		e.clear();
		tree[1].clear();
		std::priority_queue<int,std::vector<int>, std::greater<int>> min_pq;
		cin>>n;
		for(j=2;j<=n;j++){
			cin>>b;
			a.push_back(b);
			c.push_back(-1);
			d.push_back(0);
			tree[j].clear();
		}
		for(j=0;j<n-1;j++){
			cin>>u>>v>>w;
			if(a[u-1]+a[v-1]>2*w){
				e.push_back(u);
				e.push_back(v);
				e.push_back(w);
			}
			tree[u].push_back(v);
			tree[u].push_back(w);
			tree[v].push_back(u);
			tree[v].push_back(w);
		}
	    dfs(tree,c,a,d,1,-1);
	    for(j=0;j<e.size();j+=3){
	    	minu=e[j+2]-a[e[j]-1];
	    	minv=e[j+2]-a[e[j+1]-1];
	    	if(d[e[j]-1]>=minu){
	    		min_pq.push(c[e[j]-1]);
	    	}else{
	    		min_pq.push(c[e[j]-1]+minu-d[e[j]-1]);
	    	}
	    	if(d[e[j+1]-1]>=minv){
	    		min_pq.push(c[e[j+1]-1]);
	    	}else{
	    		min_pq.push(c[e[j+1]-1]+minv-d[e[j+1]-1]);
	    	}
	    }
	    for(j=1;j<n;j++){
	    	if(!min_pq.empty())if(c[j]>min_pq.top())c[j]=min_pq.top();
	    	cout<<c[j]<<" ";
	    }
	    cout<<endl;
	}
    return 0;
}