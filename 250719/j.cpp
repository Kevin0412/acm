#include<bits/stdc++.h>

using namespace std;

struct treeNode{
	vector<int> neighbors;
	long long patterned1[4];
	long long patterned2[4];
	long long successful;
	char c;
	int visited;
};

treeNode tree[1000006];

void solve(){
	int i,n,u,v,j;
	scanf("%d",&n);
	string s;
	cin>>s;
	for(i=0;i<n;i++){
		tree[i].neighbors.clear();
		tree[i].successful=0;
		for(j=0;j<4;j++){
			tree[i].patterned1[j]=0;
			tree[i].patterned2[j]=0;
		}
		tree[i].c=s[i];
		tree[i].visited=0;
	};
    for(i=0;i<n-1;i++){
    	scanf("%d %d",&u,&v);
    	tree[u-1].neighbors.push_back(v-1);
    	tree[v-1].neighbors.push_back(u-1);
    }
    
    vector<pair<int,int>> dfs;
    dfs.push_back({0,-1});
    
    while(! dfs.empty()){
    	int parent=dfs[dfs.size()-1].second;
    	int node=dfs[dfs.size()-1].first;
    	long long patterned1[4];
		long long patterned2[4];
		for(i=0;i<4;i++){
			patterned1[i]=0;
			patterned2[i]=0;
		}
	    for (int neighbor : tree[node].neighbors) {
	        if (neighbor == parent) continue;
	        if(!tree[neighbor].visited)dfs.push_back({neighbor,node});
	    }
	    if(parent!=dfs[dfs.size()-1].second | node!=dfs[dfs.size()-1].first){
	    	continue;
	    }
	    for (int neighbor : tree[node].neighbors) {
	        if (neighbor == parent) continue;
	        for(j=0;j<4;j++){
				patterned1[j]+=tree[neighbor].patterned1[j];
				patterned2[j]+=tree[neighbor].patterned2[j];
			}
			tree[node].successful+=tree[neighbor].successful;
	    }
	    if (tree[node].c=='S'){
	    	tree[node].patterned1[0]=1;
	    	tree[node].successful+=patterned2[3];
	    }else if(tree[node].c=='P'){
	    	tree[node].patterned1[3]=patterned1[2];
	    	tree[node].patterned2[1]=patterned2[0];
	    	for (int neighbor : tree[node].neighbors) {
		        if (neighbor == parent) continue;
		        tree[node].successful+=tree[neighbor].patterned1[2]*(patterned2[0]-tree[neighbor].patterned2[0]);
		    }
	    }else if(tree[node].c=='C'){
	    	tree[node].patterned1[1]=patterned1[0];
	    	tree[node].patterned2[3]=patterned2[2];
	    	for (int neighbor : tree[node].neighbors) {
		        if (neighbor == parent) continue;
		        tree[node].successful+=tree[neighbor].patterned1[0]*(patterned2[2]-tree[neighbor].patterned2[2]);
		    }
	    	tree[node].patterned1[2]=patterned1[1];
	    	tree[node].patterned2[2]=patterned2[1];
	    	for (int neighbor : tree[node].neighbors) {
		        if (neighbor == parent) continue;
		        tree[node].successful+=tree[neighbor].patterned1[1]*(patterned2[1]-tree[neighbor].patterned2[1]);
		    }
	    	tree[node].patterned2[0]=1;
	    	tree[node].successful+=patterned1[3];
	    }
	    //cerr<<node<<" "<<tree[node].c<<" "<<tree[node].successful<<endl;
	    tree[node].visited=1;
	    dfs.pop_back();
    }

    printf("%lld\n",tree[0].successful);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}