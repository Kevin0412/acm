#include<bits/stdc++.h>

using namespace std;

void solve(){
	long long l=1,r,q;
	int i;
	cin>>r;
	for(int j=0;j<4;j++){
		q=sqrt(sqrt(l))*sqrt(sqrt(r));
		cout<<"? "<<q<<endl;
		cout.flush();
		cin>>i;
		if(i){
			l=q;
		}else{
			r=q;
		}
	}
	q=sqrt(sqrt(l))*sqrt(sqrt(r));
	cout<<"! "<<q<<endl;
	cout.flush();
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}