#include<bits/stdc++.h>

using namespace std;

int is_double(long long n){
	long long l=0,r=23171,i;
	while(true){
		i=(l+r)/2;
		if(2*i*i>n){
			r=i;
		}else if(2*i*i<n){
			l=i;
		}else{
			return 1;
		}
		if(r-l==1){
			break;
		}
	}
	if(2*l*l!=n && 2*r*r!=n){
		return 0;
	}
	return 1;
}

int is_triple(long long n){
	long long l=0,r=711,i;
	while(true){
		i=(l+r)/2;
		if(3*i*i*i>n){
			r=i;
		}else if(3*i*i*i<n){
			l=i;
		}else{
			return 1;
		}
		if(r-l==1){
			break;
		}
	}
	if(3*l*l*l!=n && 3*r*r*r!=n){
		return 0;
	}
	return 1;
}

void solve(){
	long long n;
	cin>>n;
	if(is_double(n)){
		if(is_triple(n)){
			cout<<n<<" is a triple flower\n";
			return;
		}
		cout<<n<<" is a double flower\n";
		return;
	}
	cout<<n<<" is "<<n<<"\n";
	return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}