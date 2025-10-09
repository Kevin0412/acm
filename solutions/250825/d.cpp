#include<bits/stdc++.h>

using namespace std;

struct cmd{
	int a;
	int x;
	int b;
	int y;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<cmd> c;
	c.push_back({0,0,0,0});
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,x,b,y;
		string s;
		cin>>s;
		if(s[0]=='H'){
			a=0;
			x=0;
		}else{
			cin>>a>>s>>s;
			x=0;
			for(int j=0;j<s.length()-1;j++){
				x*=10;
				x+=(int)(s[j]-'0');
			}
		}
		cin>>s>>b>>s>>y;
		c.push_back({a,x,b,y});
		cerr<<a<<" "<<x<<" "<<b<<" "<<y<<endl;
	}
	int cp=1,cn=0;
	vector<int> d;
	while(cp>=1){
		cerr<<cp<<" ";
		if(c[cp].a==0){
			if(d.empty()){
				cp=0;
			}else{
				d.push_back(c[cp].b);
				cp=c[cp].y;
			}
		}else{
			if(!d.empty()){
				if(c[cp].a==d.back()){
					d.pop_back();
					cp=c[cp].x;
				}else{
					d.push_back(c[cp].b);
					cp=c[cp].y;
				}
			}else{
				d.push_back(c[cp].b);
				cp=c[cp].y;
			}
		}
		cn++;
	}
	cout<<cn<<"\n";
	return 0;
}