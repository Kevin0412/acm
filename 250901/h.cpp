#include<bits/stdc++.h>

using namespace std;

struct node{
	int parent;
	vector<int> children;
	int n;
};

void solve(){
	int n,k;
	cin>>n>>k;
	//cerr<<n<<"  "<<k<<"\n";
	vector<pair<int,int>> a(k),a1(k);
	vector<node> ans(n+1,{0,vector<int>(0),0});
	for(int i=0;i<k;i++){
		cin>>a[i].first>>a[i].second;
		a1[i].first=a[i].first;
		a1[i].second=a[i].second;
	}
	sort(a.begin(),a.end(),[](auto x,auto y){return x.second-x.first>y.second-y.first;});
	if(a.size()!=1){
		int c=a[0].second-a[0].first;
		int flag=-1;
		for(auto i:a){
			if(i.second-i.first==c)flag++;
			if(!(i.second-i.first==c | i.second-i.first==c-1)){
				flag=0;
				break;
			}
		}
		if(flag){
			cout<<"IMPOSSIBLE\n";
			return;
		}
	}
    vector<int> new_chain(a[0].second-a[0].first+2,0);
    new_chain[a[0].second-a[0].first]=a[0].first;
    new_chain[a[0].second-a[0].first+1]=a[0].first;
    ans[a[0].first].parent=0;
	for(int i=1;i<=a[0].second-a[0].first;i++){
		ans[a[0].first+i].parent=a[0].first+i-1;
		ans[a[0].first+i-1].children.push_back(a[0].first+i);
		new_chain[a[0].second-a[0].first-i]=a[0].first+i;
	}
	for(int j=1;j<a.size();j++){
		ans[a[j].first].parent=new_chain[a[j].second-a[j].first+1];
		ans[new_chain[a[j].second-a[j].first+1]].children.push_back(a[j].first);
		for(int i=1;i<=a[j].second-a[j].first;i++){
			ans[a[j].first+i].parent=a[j].first+i-1;
			ans[a[j].first+i-1].children.push_back(a[j].first+i);
		}
	}
	//for(int i=1;i<=n;i++){
		//cerr<<i<<"  ";
		//for(auto j:ans[i].children){
			//cerr<<j<<" ";
		//}
		//cerr<<"\n";
	//}
	vector<int> dfs;
	dfs.push_back(a[0].first);
	while(!dfs.empty()){
		int k=dfs.back();
		//cerr<<k<<" ";
		if(ans[k].children.empty()){
			ans[k].n=1;
			dfs.pop_back();
		}else{
			vector<int> unvisited;
			ans[k].n=1;
			for(auto i:ans[k].children){
				if(ans[i].n==0){
					unvisited.push_back(i);
				}else{
					ans[k].n+=ans[i].n;
				}
			}
			if(unvisited.empty()){
				dfs.pop_back();
			}else{
				for(auto i:unvisited){
					dfs.push_back(i);
				}
			}
		}
	}
	//cerr<<"\n";
	//for(int i=1;i<=n;i++){
		//cerr<<ans[i].n<<" ";
	//}
	//cerr<<"\n";
	int m=0;
	for(int i=1;i<=n;i++){
		if(i>a1[m].second){
			m++;
		}
		if(!ans[i].children.empty()){
			int maxn=1;
			int flag=0;
			for(auto j:ans[i].children){
				maxn=max(ans[j].n,maxn);
				if(j==i+1){
					flag=1;
				}
				//cerr<<j<<" "<<ans[j].n<<"\n";
			}
			if(!flag){
				cout<<"IMPOSSIBLE\n";
				return;
			}
			//cerr<<maxn<<"\n";
			if(a1[m].second==i){
				cout<<"IMPOSSIBLE\n";
				return;
			}
			if(maxn!=ans[i+1].n){
				cout<<"IMPOSSIBLE\n";
				return;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i].parent<<" ";
	}
	cout<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}