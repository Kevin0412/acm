#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int ones=0,zeros=0;
		for(char j:s){
			if(j=='1'){
				ones++;
			}else zeros++;
		} 
		cout<<ones*n-ones+zeros<<endl;
	}
	return 0;
}