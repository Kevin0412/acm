#include <bits/stdc++.h>
using namespace std;

long long MOD=998244353;

struct{
	int right[26];
	long long dp;
} a[1000006];

char s[1000006];

void solve(){
	int i,j,n,k,firstLetter[26];
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	for(j=0;j<26;j++)firstLetter[j]=n;
	for(i=0;i<n;i++){
		firstLetter[s[i]-'a']=min(firstLetter[s[i]-'a'],i);
	}
	for(i=0;i<=n;i++){
		for(j=0;j<26;j++){
			a[i].right[j]=-1;
		}
		a[i].dp=-1;
	}
	for(i=n-k-2;i>=0;i--){
		for(j=0;j<26;j++){
			a[i].right[j]=a[i+1].right[j];
		}
		a[i].right[s[i+k+1]-'a']=i+k+1;
	}
	vector<int> dfs;
	long long ans=0;
	for(j=0;j<26;j++){
		if(firstLetter[j]!=n){
			if(a[firstLetter[j]].dp==-1)
			    dfs.push_back(firstLetter[j]);
		}
		while(!dfs.empty()){
			int b=dfs[dfs.size()-1];
			for(i=0;i<26;i++){
				if(a[b].right[i]!=-1){
					if(a[a[b].right[i]].dp==-1)
					    dfs.push_back(a[b].right[i]);
				}
			}
			if(b!=dfs[dfs.size()-1]) continue;
			a[b].dp=1;
			for(i=0;i<26;i++){
				if(a[b].right[i]!=-1){
					a[b].dp+=a[a[b].right[i]].dp;
				}
			}
			a[b].dp%=MOD;
			//cerr<<b<<" "<<a[b].dp<<endl;
			dfs.pop_back();
		}
	}
	for(j=0;j<26;j++){
		if(firstLetter[j]!=n){
			ans+=a[firstLetter[j]].dp;
		}
	}
	ans%=MOD;
	printf("%lld\n",ans);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}