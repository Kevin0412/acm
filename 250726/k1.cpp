#include<bits/stdc++.h>
 
using namespace std;
 
void solve(){
	int a,b,c;
	string sa,sb,sc;
	cin>>a>>b>>c>>sa>>sb>>sc;
	if(sa[0]=='M' & sb[0]=='S' & sc[0]=='T'){
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;
}
 
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}