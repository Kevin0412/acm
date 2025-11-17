#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+10;
const int LOG=20;
int up[N][LOG],dep[N];
vector<int> g[N];
vector<int> ans;

template<typename T>
void read(T &x){
	x=0;
	T f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

struct node{
	vector<int> sons;
	int c;
	int parent;
	int max_son;
	int max2_son;
	int dp;
};

void build(int root=1){
	stack<pair<int,int>> st;
	st.push({root,0});
	dep[root]=0;
	while(!st.empty()){
		auto [u,p]=st.top();st.pop();
		up[u][0]=p;
		for(int k=1;k<LOG;++k){
			up[u][k]=up[up[u][k-1]][k-1];
		}
		for(int v:g[u]){
			if(v==p){
				continue;
			}
			dep[v]=dep[u]+1;
			st.push({v,u});
		}
	}
}

bool lca(int a,int b){
	if(dep[a]<dep[b]){
		return false;
	}
	int d=dep[a]-dep[b];
	for(int k=0;k<LOG;++k){
		if(d>>k&1)a=up[a][k];
	}
	if(a==b) return true;
	else return false;
}

//long long ans=0;
void solve(){
	int n,m;
	//cin>>n>>m;
	read(n);
	read(m);
	vector<node> e(n+1,{vector<int>(0),0,0,-1,-1,0}); 
	memset(up,0,sizeof(up));
	memset(dep,0,sizeof(dep));
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++)
	{
		//cin>>e[i].c;
		read(e[i].c);
	}
	for(int i=1;i<n;i++){
		if(1==n) break;
		int fa,so;
		//cin>>fa>>so;
		read(fa);
		read(so);
		e[fa].sons.push_back(so);
		e[so].sons.push_back(fa);
		g[fa].push_back(so);
		g[so].push_back(fa);
	}
	build(1);
	vector<int> dfs;
	////cerr<<"C\n";
	dfs.push_back(1);
	while(!dfs.empty()){
		node &k=e[dfs.back()];
		int p=dfs.back();
		dfs.pop_back();
		for(auto i:k.sons){
			if(i!=k.parent){
				dfs.push_back(i);
				e[i].parent=p;
			}
		}
	}
	////cerr<<"b\n";
	dfs.push_back(1);
	vector<int> visited(n+1,0);
	while(!dfs.empty()){
		//cout<<dfs.back()<<"\n";
		node &k=e[dfs.back()];
		int flag=0;
		for(auto i:k.sons){
			if(i!=k.parent)
			if(!visited[i]){
				dfs.push_back(i);
				flag=1;
			}
		}
		if(flag){
			continue;
		}
		//cerr<<k.c<<"\n";
		visited[dfs.back()]=1;
		dfs.pop_back();
		if(k.sons.size()==1){
			k.max2_son=0;
			k.max_son=0;
			continue;
		}
		vector<int> c1;
		for(auto i:k.sons){
			if(i!=k.parent)
			c1.push_back(e[i].c);
		}
		//std::sort(c1.begin(),c1.end());
		k.max_son=c1[0];
		for(auto i:c1){
			k.max_son=min(k.max_son,i);
		}
		int flag1=0;
		if(k.max_son==c1[0]){
			k.max2_son=c1[1];
		}else{
			k.max2_son=c1[0];
		}
		for(auto i:c1){
			if(i==k.max_son){
				if(!flag1){
					flag1=1;
				}else{
					k.max2_son=k.max_son;
					break;
				}
			}else{
				k.max2_son=min(k.max2_son,i);
			}
		}
		k.c=min(k.c,k.max2_son+k.max_son);
	}
	////cerr<<"a\n";
	dfs.push_back(1);
	while(!dfs.empty()){
		node &k=e[dfs.back()];
		dfs.pop_back();
		for(auto i:k.sons){
			if(i!=k.parent){
				dfs.push_back(i);
				if(k.max2_son==k.max_son){
					e[i].dp=k.dp+k.max_son;
				}else{
					if(e[i].c==k.max_son){
						e[i].dp=k.dp+k.max2_son;
					}else{
						e[i].dp=k.dp+k.max_son;
					}
				}
				//cout<<i<<""<<e[i].dp<<"In";
			}
		}
	}
	int x,y;
	for(int i=0;i<m;i++){
		//cin>>x>>y;
		read(x);
		read(y);
		if(!lca(x,y)){
			ans.push_back(-1);
			continue;
		}
		if(x==y){
			ans.push_back(0);
			continue;
		}
		ans.push_back(e[x].dp-e[y].dp);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	cout.tie(0);
	int t;
	//cin>>t;
	read(t);
	while(t--){
		solve();
	}
	for(auto i:ans)cout<<i<<'\n';
	return 0;
}
	