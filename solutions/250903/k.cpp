#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	string a,b;
	cin>>n>>a>>b;
	for(int i=0;i<n-1;i++){
		if(!(a[i]=='1' | b[i]=='1')){
			cout<<"0\n";
			return 0;
		}
	}
	cout<<"1\n";
	return 0;
}