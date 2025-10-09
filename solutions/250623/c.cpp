#include<bits/stdc++.h>

using namespace std;

int main(){
	int i,t,j,k,n,a[5001],down,ans,down_l,down_r;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n;
		for(j=0;j<n;j++){
			cin>>a[j];
		}
		down=0;
		ans=0;
	    for(j=n-1;j>1;j--){
	    	for(k=j-1;k>0;k--){
	    		//if(a[j]>=2*a[k])break;
	    		//if(a[n-1]-a[j]-a[k]+1>=a[k])break;
	    		down_l=-1;
	    		down_r=k;
	    		down=max(a[n-1]-a[j]-a[k]+1,a[j]-a[k]+1);
	    		//cerr<<down<<" "<<a[k]<<" "<<a[j]<<" "<<a[n-1]<<endl;
	    		while(down_r-down_l>1){
	    			if(a[(down_l+down_r)/2]<down){
		    			down_l=(down_l+down_r)/2;
		    		}else{
		    			down_r=(down_l+down_r)/2;
		    		}
	    		}
	    		ans+=k-down_r;
	    	}
	    }
	    cout<<ans<<endl;
	}
	return 0;
}