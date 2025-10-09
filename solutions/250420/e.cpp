#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll n,m;
	cin>>n>>m;
	ll num[m],f=0,c[n],i;
	vector<ll> fs,es;
	set<ll> cs;
	int flag=1;
	for(i=0;i<m;i++){
		num[i]=0;
	}
	for(i=0;i<n;i++){
		cin>>c[i];
		num[c[i]-1]++;
		if(flag){
			cs.insert(c[i]);
			//cerr<<cs.size()<<endl;
			if(cs.size()==m){
				flag=0;
			}
		}
		if(!flag){
			while(num[c[f]-1]>1){
				num[c[f]-1]--;
				f++;
			}
			fs.push_back(f);
			es.push_back(i);
			//cerr<<f<<" "<<i<<" "<<num[c[f]-1]<<" "<<c[f]<<endl;
		}
	}
	ll min=es[0]-fs[0],minf=fs[0],mine=es[0];
	for(int i=1;i<fs.size();i++){
		if(min>es[i]-fs[i]){
			min=es[i]-fs[i];
			minf=fs[i];
			mine=es[i];
		}
	}
	cout<<minf+1<<" "<<mine+1<<endl;
	return 0;
}