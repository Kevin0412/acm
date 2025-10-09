#include<bits/stdc++.h>

using namespace std;

void solve(){
	int i,n,b;
	scanf("%d",&n);
	vector<int> a;
	for(i=0;i<n;i++){
		scanf("%d",&b);
		a.push_back(b);
	}
	int sum=0;
	for(i=0;i<n-1;i++){
		sum+=a[i];
		if(sum<=i*2){
			printf("No\n");
			return;
		}
	}
	sum+=a[n-1];
	if(sum==(n-1)*2){
		printf("Yes\n");
		return;
	}
	printf("No\n");
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}