#include<bits/stdc++.h>

using namespace std;

int main(){
	int i,t,a,x,y;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>a>>x>>y;
		if(x<y){
			if(a>=x & a<=y){
				cout<<"NO"<<endl;
			}else{
				cout<<"YES"<<endl;
			}
		}else{
			if(a>=y & a<=x){
				cout<<"NO"<<endl;
			}else{
				cout<<"YES"<<endl;
			}
		}
	}
	return 0;
}