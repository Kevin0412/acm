#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n,m,k,w;
	cin>>n>>m>>k>>w;
	vector<int> red(n);
	vector<int> black(m+2);
	black[0]=0;
	black[m+1]=w+1;
	for(int i=0;i<n;i++){
		cin>>red[i];
	}
	for(int i=1;i<=m;i++){
		cin>>black[i];
	}
	sort(red.begin(),red.end());
	sort(black.begin(),black.end());
	vector<int> ans;
	int j=0,prev_j=0;
	for(int i=0;i<=m;i++){
		prev_j=j;
		if(j>=red.size()){
			break;
		}
		while(red[j]<black[i+1]){
			j++;
			if(j>=red.size()){
				break;
			}
		}
		if(j==prev_j){
			continue;
		}
		int max_a=(black[i+1]-black[i]-1)/k;
		vector<int> ans1;
		int l=0;
	    int	prev_l=0;
		while(true){
			prev_l=l;
			ans1.push_back(red[prev_j+l]);
		    while(red[prev_j+l]<red[prev_j+prev_l]+k){
		    	l++;
		    	if(l>=j-prev_j){
		    		break;
		    	}
		    }
		    if(l>=j-prev_j){
	    		break;
	    	}
		}
		if(ans1.size()>max_a){
			cout<<"-1\n";
			return;
		}
		int q=1;
		for(int p=ans1.size()-1;p>=0;p--){
			if(black[i+1]-k*q<ans1[p]){
				ans1[p]=black[i+1]-k*q;
			}else{
				break;
			}
			q++;
		}
		for(auto i:ans1){
			ans.push_back(i);
		}
	}
    cout<<ans.size()<<"\n";
    for(auto i:ans){
		cout<<i<<" ";
	}
	cout<<"\n";
}

signed main(){
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
