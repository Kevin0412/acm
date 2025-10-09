#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,i,a[100001],dp[30],maxb,c,b[30];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<30;i++){
    	dp[i]=0;
    }
    for(i=0;i<n;i++){
    	maxb=0;
    	c=0;
    	for(c=0;c<30;c++){
    		b[c]=a[i]%2;
    		a[i]/=2;
    		if(b[c]){
    			maxb=max(dp[c]+1,maxb);
    		}
    	}
    	for(c=0;c<30;c++){
            if(b[c])dp[c]=maxb;
    	}
    }
    maxb=0;
    for(c=0;c<30;c++){
    	maxb=max(dp[c],maxb);
    }
    cout<<maxb<<endl;
    return 0;
}
