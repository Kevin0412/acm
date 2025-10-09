#include<bits/stdc++.h>

using namespace std;
#define ll long long

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int a1,b1,c1,a,b,c;
		cin>>a1>>b1>>c1;
		vector<int> d={a1,b1,c1};
		sort(d.begin(),d.end());
		a=d[0];
		b=d[1];
		c=d[2];
		if(lcm(a,b)==c){
			vector<int> A(c,0),B(c,0),C(c,0);
			if(a==2 & b==2){
				cout<<"NO\n";
				continue;
			}
			if(b!=2){
				for(int i=0;i<c;i+=a){
					for(int j=0;j<1;j++){
						A[i+j]=1;
					}
				}
				for(int i=0;i<c;i+=b){
					for(int j=0;j<2;j++){
						B[i+j]=1;
					}
				}
			}else{
				for(int i=0;i<c;i+=b){
					for(int j=0;j<1;j++){
						B[i+j]=1;
					}
				}
			}
			for(int i=0;i<c;i++){
				C[i]=A[i]^B[i];
			}
			cout<<"YES\n";
			int i;
			vector<int> used(3,0);
			for(i=0;i<3;i++){
				if(a1==d[i] & !used[i]){
					used[i]=1;
					break;
				}
			}
			if(i==0){
				for(int i=0;i<a;i++){
					cout<<A[i];
				}
			}else if(i==1){
				for(int i=0;i<b;i++){
					cout<<B[i];
				}
			}else{
				for(int i=0;i<c;i++){
					cout<<C[i];
				}
			}
			cout<<"\n";
			for(i=0;i<3;i++){
				if(b1==d[i] & !used[i]){
					used[i]=1;
					break;
				}
			}
			if(i==0){
				for(int i=0;i<a;i++){
					cout<<A[i];
				}
			}else if(i==1){
				for(int i=0;i<b;i++){
					cout<<B[i];
				}
			}else{
				for(int i=0;i<c;i++){
					cout<<C[i];
				}
			}
			cout<<"\n";
			for(i=0;i<3;i++){
				if(c1==d[i] & !used[i]){
					used[i]=1;
					break;
				}
			}
			if(i==0){
				for(int i=0;i<a;i++){
					cout<<A[i];
				}
			}else if(i==1){
				for(int i=0;i<b;i++){
					cout<<B[i];
				}
			}else{
				for(int i=0;i<c;i++){
					cout<<C[i];
				}
			}
			cout<<"\n";
		}else{
			cout<<"NO\n";
			continue;
		}
	}
}