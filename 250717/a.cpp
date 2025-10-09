#include<bits/stdc++.h>

using namespace std;

int main(){
	long long a,b,c;
	cin>>a>>b>>c;
	if(a==b & b==c){
		cout<<a+b+c+100<<endl;
	}else{
		cout<<a+b+c<<endl;
	}
	return 0;
}
