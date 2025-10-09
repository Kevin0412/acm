#include<bits/stdc++.h>

using namespace std;

void dfs(int v,vector<int> a[],int p,int c){
	int u,i;
	for(i=0;i<(a[v-1]).size();i++){
		u=a[v-1][i];
		if(u!=p){
			if(c)cout<<u<<" "<<v<<endl;
			else cout<<v<<" "<<u<<endl;
			dfs(u,a,v,1-c);
		}
	}
}

int main(){
	int i,t,n,j,u,v,flag;
	vector<int> a[200001];
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n;
		for(j=0;j<n;j++){
			a[j].clear();
		}
		for(j=0;j<n-1;j++){
			cin>>u>>v;
			a[u-1].push_back(v);
			a[v-1].push_back(u);
		}
		flag=0;
		for(j=0;j<n;j++){
			if((a[j]).size()==2){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"YES"<<endl;
			cout<<j+1<<" "<<a[j][0]<<endl;
			cout<<a[j][1]<<" "<<j+1<<endl;;
			dfs(a[j][0],a,j+1,1);
			dfs(a[j][1],a,j+1,0);
			continue;
		}
		cout<<"NO"<<endl;
	}
	return 0;
}