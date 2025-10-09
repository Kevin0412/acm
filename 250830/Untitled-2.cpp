#include<bits/stdc++.h>
#include <cctype>   // isdigit
#include <cstdio>   // getchar

using namespace std;
template <typename T>
void read(T &x) {
    x = 0;
    T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
}

void solve(){
	int n,m,q;
	read(n);
	read(m);
	read(q);
	vector<pair<int,int>> a;
	//vector<vector<int>> game(n,vector<int>(m+1,0));
	vector<vector<pair<int,int>>> game(n);
	// for(int i=0;i<n;i++){
		// game[i][0]=m;
	// }
	for(int i=1;i<=m;i++){
		a.push_back({0,i});
	}
	int g=0;
	for(int i=0;i<q;i++){
		int c;
		int id,x;
		read(c);
		if(c==1){
			read(g);
		}else{
			read(id);
			read(x);
			if(g==x){
				game[g-1].push_back({c,id});
			}
		}
	}
	for(int i=0;i<n;i++){
		int k=m;
		vector<int> ga(m,0);
		for(auto gam:game[i]){
			if(gam.first==2){
				if(ga[gam.second-1]==0){
					ga[gam.second-1]=k;
					a[gam.second-1].first+=k;
				    k--;
				}
			}else if(gam.first==3){
				if(ga[gam.second-1]==0){
					ga[gam.second-1]=-1;
				}
			}
		}
		// for(int j=0;j<m;j++){
			// if(ga[j]>0){
				// a[j].first+=ga[j];
			// }
		// }
	}
	sort(a.begin(),a.end(),[](pair<int,int> x,pair<int,int> y){
		if(x.first==y.first){
			return x.second<y.second;
		}
		return x.first>y.first;
	});
	for(auto i:a){
		//cout<<i.second<<" "<<i.first<<"\n";
		printf("%d %d\n",i.second,i.first);
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	
	int t;
	read(t);
	while(t--)solve();
	return 0;
}