#include<bits/stdc++.h>
 
using namespace std;
 
void solve(){
	double a[1003],b[1003],c[1003],sa=0.0,sb=0.0,sc=0.0,s;
	int n,m,p,i;
	cin>>n>>m>>p;
	for(i=0;i<n;i++){
		cin>>a[i];
		sa+=a[i];
	}
	for(i=0;i<m;i++){
		cin>>b[i];
		sb+=b[i];
	}
	for(i=0;i<p;i++){
		cin>>c[i];
		sc+=c[i];
	}
	//cerr<<sa<<" "<<sb<<" "<<sc<<endl;
	s=sa+sb+sc;
	s/=3;
	double ans[6];
	if(sa>=s){
		ans[0]=0;
		ans[1]=0;
	}
	if(sb>=s){
		ans[2]=0;
		ans[3]=0;
	}
	if(sc>=s){
		ans[4]=0;
		ans[5]=0;
	}
	/*
	0 ab 
	1 ac
	2 ba
	3 bc
	4 ca
	5 cb
	*/
	if(sa<s & sb<s){
		ans[1]=s-sa;
		ans[3]=s-sb;
	}else if(sa<s & sc<s){
		ans[0]=s-sa;
		ans[5]=s-sc;
	}else if(sb<s & sc<s){
		ans[2]=s-sb;
		ans[4]=s-sc;
	}else if(sa<s){
		ans[0]=sb-s;
		ans[1]=sc-s;
	}else if(sb<s){
		ans[2]=sa-s;
		ans[3]=sc-s;
	}else if(sc<s){
		ans[4]=sa-s;
		ans[5]=sb-s;
	}
	for(i=0;i<6;i++){
		ans[i]=round(ans[i]*100.0)/100.0;
	}
	sa+=-ans[0]-ans[1]+ans[2]+ans[4];
	sb+=ans[0]-ans[2]-ans[3]+ans[5];
	sc+=ans[1]+ans[3]-ans[4]-ans[5];
	double maxs=max(sa,max(sb,sc));
	double mins=min(sa,min(sb,sc));
	if(maxs-mins>0.01){
		if(sa==maxs & sb==mins & sc==mins){
			ans[0]+=0.01;
			ans[1]+=0.01;
		}else if(sa==maxs & sb==maxs & sc==mins){
			ans[1]+=0.01;
			ans[3]+=0.01;
		}else if(sa==maxs & sb==mins & sc==maxs){
			ans[0]+=0.01;
			ans[5]+=0.01;
		}else if(sa==mins & sb==maxs & sc==mins){
			ans[2]+=0.01;
			ans[3]+=0.01;
		}else if(sa==mins & sb==mins & sc==maxs){
			ans[4]+=0.01;
			ans[5]+=0.01;
		}else if(sa==mins & sb==maxs & sc==maxs){
			ans[2]+=0.01;
			ans[4]+=0.01;
		}
	}
	/*
	0 ab 
	1 ac
	2 ba
	3 bc
	4 ca
	5 cb
	*/
	for(i=0;i<6;i++){
		printf("%.2f ",ans[i]);
	}
	cout<<endl;
}
 
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}