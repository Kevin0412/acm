#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int a,b;
	cin>>a>>b;
	if(a==1 && b==1){
		cout<<"Yes\n0\n0\n";
		return;
	}
	if(a==1){
		cout<<"Yes\n1\n";
		for(int i=0;i<b;i++){
			cout<<i<<" ";
		}
		cout<<"\n";
		return;
	}
	if(b==1){
		cout<<"Yes\n";
		for(int i=0;i<a;i++){
			cout<<i<<" ";
		}
		cout<<"\n1\n";
		return;
	}
	// if(a==2 & b%2!=0){
		// cout<<"Yes\n";
		// cout<<"1 2\n";
		// for(int i=0;i<b;i++){
			// cout<<i*2+1<<" ";
		// }
		// cout<<"\n";
		// return;
	// }
	// if(b==2 & a%2!=0){
		// cout<<"Yes\n";
		// for(int i=0;i<a;i++){
			// cout<<i*2+1<<" ";
		// }
		// cout<<"\n1 2\n";
		// return;
	// }
	if(a<b){
		vector<int> as;
		for(int i=1;i<=a;i++){
			int flag=1;
			for(int j=0;j<b;j++){
				if(gcd(a*j+i,b)==1){
					as.push_back(a*j+i);
					flag=0;
					break;
				}
			}
			if(flag){
				cout<<"No\n";
				return;
			}
		}
		cout<<"Yes\n";
		for(auto i:as){
			cout<<i<<" ";
		}
		cout<<"\n";
		for(int i=0;i<b;i++){
			cout<<i*a+1<<" ";
		}
		cout<<"\n";
		return;
	}else{
		vector<int> bs;
		for(int i=1;i<=b;i++){
			int flag=1;
			for(int j=0;j<a;j++){
				if(gcd(b*j+i,a)==1){
					bs.push_back(b*j+i);
					flag=0;
					break;
				}
			}
			if(flag){
				cout<<"No\n";
				return;
			}
		}
		cout<<"Yes\n";
		for(int i=0;i<a;i++){
			cout<<i*b+1<<" ";
		}
		cout<<"\n";
		for(auto i:bs){
			cout<<i<<" ";
		}
		cout<<"\n";
		return;
	}
	// if(a<b){
		// for(int i=1;i<=a;i++){
			// cout<<i<<" ";
		// }
		// cout<<"\n";
		// for(int i=0;i<b;i++){
			// cout<<i*a+1<<" ";
		// }
		// cout<<"\n";
	// }else{
		// for(int i=0;i<a;i++){
			// cout<<i*b+1<<" ";
		// }
		// cout<<"\n";
		// for(int i=1;i<=b;i++){
			// cout<<i<<" ";
		// }
		// cout<<"\n";
	// }
	cout<<"No\n";
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