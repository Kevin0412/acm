#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<string> a(7,"");
	cin>>a[0];
	cin>>a[6];
	int an=0,bn=0;
	for(int i=0;i<n;i++){
		if(a[0][i]=='#')an++;
		if(a[6][i]=='#')bn++;
	}
	if(an==0 | an==n){
		if(bn==0 | bn==n){
			cout<<"Yes\n";
			for(int i=0;i<6;i++){
				cout<<a[0]<<"\n";
			}
			cout<<a[6]<<"\n";
			return;
		}
		else{
			cout<<"No\n";
			return;
		}
	}
	if(bn==0 | bn==n){
		cout<<"No\n";
		return;
	}
	cout<<"Yes\n";
	for(int i=0;i<n;i++){
		if(a[0][i]=='#'){
			a[1]+='.';
		}else{
			a[1]+='#';
		}
		a[2]+='.';
		a[3]+='.';
		a[4]+='.';
		if(a[6][i]=='#'){
			a[5]+='.';
		}else{
			a[5]+='#';
		}
	}
	int c=-1,d=-1;
	if(a[1][0]=='#'){
		for(int i=1;i<n;i++){
			if(a[1][i]=='.'){
				a[2][i]='#';
				c=i;
				break;
			}
		}
	}else{
		for(int i=1;i<n;i++){
			if(a[1][i]=='#'){
				a[2][i-1]='#';
				c=i-1;
				break;
			}
		}
	}
	if(a[5][0]=='#'){
		for(int i=1;i<n;i++){
			if(a[5][i]=='.'){
				a[4][i]='#';
				d=i;
				break;
			}
		}
	}else{
		for(int i=1;i<n;i++){
			if(a[5][i]=='#'){
				a[4][i-1]='#';
				d=i-1;
				break;
			}
		}
	}
	if(abs(c-d)<=1){
		a[3][c]='#';
	}else{
		for(int i=min(c,d)+1;i<max(c,d);i++){
			a[3][i]='#';
		}
	}
	for(int i=0;i<7;i++){
		cout<<a[i]<<"\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}