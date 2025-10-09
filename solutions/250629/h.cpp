#include<bits/stdc++.h>
using namespace std;

double PI_125=39.269908169872416;
double SQRT_2_50=70.71067811865476;
double A=38.268343236508976;
double B=92.38795325112868;

void solve(){
	char a[4];
	cin>>a;
	int b=(int)(a[0]-a[2]+8)%8;
	if(a[1]=='-'){
		if(b==0){
			printf("%.10lf\n",0.0);
			return;
		}
		if(b==1 | b==7){
			printf("%.10lf\n",A);
			return;
		}
		if(b==2 | b==6){
			printf("%.10lf\n",SQRT_2_50);
			return;
		}
		if(b==3 | b==5){
			printf("%.10lf\n",B);
			return;
		}
		printf("%.10lf\n",100.0);
		return;
	}
	if(a[1]=='>'){
		printf("%.10lf\n",PI_125*(double)(8-b));
		return;
	}
	if(a[1]=='<'){
		printf("%.10lf\n",PI_125*(double)(b));
		return;
	}
	printf("%.10lf\n",100.0);
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