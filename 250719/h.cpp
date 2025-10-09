#include<bits/stdc++.h>

using namespace std;

void solve(){
	int x1,y1,x2,y2,dis,ans;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	dis=max(abs(x1-x2),abs(y1-y2));
	ans=(dis+1)/2;
	if(x1==x2 | y1==y2){
		if(ans%2==1){
			ans++;
		}
	}
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}