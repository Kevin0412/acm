#include<bits/stdc++.h>

using namespace std;

struct node{
	int n;
	long long w;
	int in;
	int out;
	bool operator<(const node& other) const {
        return n > other.n;
    }
} a[100005];

vector<int> b[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long w;
		cin>>w;
		a[i].n=i;
		a[i].w=w;
		a[i].in=0;
		a[i].out=0;
		b[i].clear();
	}
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		b[u].push_back(v);
		a[u].out++;
		a[v].in++;
	}
	priority_queue<node> pq;
	vector<int> ans1;
	vector<pair<int,long long>> ans2;
	for(int i=1;i<=n;i++){
		if(a[i].in==0){
			pq.push(a[i]);
		}
	}
	while(!pq.empty()){
		auto k=pq.top();
		ans1.push_back(k.n);
		pq.pop();
		if(a[k.n].out==0){
			ans2.push_back({a[k.n].n,a[k.n].w});
		}
		for(auto i:b[k.n]){
			a[i].in--;
			if(a[i].in==0)pq.push(a[i]);
			a[i].w+=a[k.n].w;
		}
	}
	for(auto i:ans1){
		cout<<i<<" ";
	}
	cout<<"\n";
	sort(ans2.begin(),ans2.end());
	for(auto i:ans2){
		cout<<i.second<<" ";
	}
	cout<<"\n";
	return 0;
}