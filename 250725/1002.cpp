#include<bits/stdc++.h>

using namespace std;

long long b[1000006],c[1000006];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int i,n;
		long long m,bi,ci,sb=0;
		scanf("%d%lld",&n,&m);
		for(i=0;i<n;i++){
			scanf("%lld",&bi);
			if(bi<b[i-1]){
				b[i]=b[i-1];
			}else{
				b[i]=bi;
			}
			sb+=b[i];
		}
		for(i=0;i<n;i++){
			scanf("%lld",&ci);
			c[i]=ci;
		}
		if(sb>m){
			 printf("NO\n");
			 continue;
		}
		for(i=n-1;i>0;i--){
			if(c[i]<c[i-1]){
				c[i-1]=c[i];
			}
		}
		long long sc=0;
		for(i=1;i<n;i++){
			sc+=c[i];
		}
		if(m<=sc){
			printf("YES\n");
		}else{
		    printf("NO\n");	
		}
	}
	return 0;
}