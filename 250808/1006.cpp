#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false); 
    cin.tie(0), cout.tie(0); 
    int t;
    cin>>t;
    while(t--){
    	long long n,k,a,b,c,d;
    	cin>>k>>n>>a>>b>>c>>d;
    	long long ansa1,ansb1,ansa2=0,ansb2=1;
    	ansa1=c*((d*k)/(c*n)+1);
    	ansb1=d;
    	long long i=(d*k)/(c*n)+1;
    	if(k*b>=a*i*n){
    		ansa2=k*(i+1);
    		ansb2=n*i;
    	}
    	long long ansa,ansb;
    	if(ansa1*ansb2>ansa2*ansb1){
    		ansa=ansa1;
    		ansb=ansb1;
    	}else{
    		ansa=ansa2;
    		ansb=ansb2;
    	}
    	long long g=gcd(ansa,ansb);
    	cout<<ansa/g<<"/"<<ansb/g<<endl;
    }
    return 0;
}
