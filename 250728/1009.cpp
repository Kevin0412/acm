#include<bits/stdc++.h>

using namespace std;

long long a[100005];

void solve(){
	int i,n;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=0;
    for(i=0;i<n;i++){
    	sum+=a[i];
    	if(a[i]==0){
    		cout<<"NO"<<endl;
    		return;
    	}
    }
    if(sum>=2*(n-1)){
    	cout<<"YES"<<endl;
    }else{
    	cout<<"NO"<<endl;
    }
}

int main(){
	ios::sync_with_stdio(false); // 关闭输入输出同步
    cin.tie(nullptr);            // 解绑cin和cout
    
    int t;
    cin>>t;
    while(t--)solve();
    
    return 0;
}