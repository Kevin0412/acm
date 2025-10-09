#include<bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	queue<pair<long long,long long>> a,b;
	for(int i=1;i<=n;i++){
		long long x,y;
		cin>>x>>y;
		a.push({x,y});
	}
	for(int i=1;i<=m;i++){
		long long x,y;
		cin>>x>>y;
		b.push({x,y});
	}
	while(!a.empty() & !b.empty()){
		//cerr<<a.front().first<<" "<<a.front().second<<"  "<<b.front().first<<" "<<b.front().second<<endl;
		int k=min((a.front().first+b.front().second-1)/b.front().second,(b.front().first+a.front().second-1)/a.front().second);
		a.front().first-=b.front().second*k;
		b.front().first-=a.front().second*k;
		//cerr<<a.front().first<<" "<<a.front().second<<"  "<<b.front().first<<" "<<b.front().second<<endl;
		if(a.front().first<=0){
			a.pop();
		}
		if(b.front().first<=0){
			b.pop();
		}
	}
	if(!b.empty()){
		cout<<"QAQ\n";
		return 0;
	}
	if(!a.empty()){
		cout<<"Win\n";
		return 0;
	}
	cout<<"Fine\n";
	return 0;
}