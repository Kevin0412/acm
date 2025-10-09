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
	long long n;
	cin>>n;
	int i=31,cn=1;
	vector<cmd> ans;
	if(n!=1){
		for(i=0;i<=32;i++){
			if(n<=(1LL<<i)+1){
				int end=cn+i-1;
				//cout<<"POP "<<cn<<" GOTO "<<end+1<<"; PUSH "<<cn<<" GOTO "<<end<<"\n";
				ans.push_back({cn,end+1,cn,end});
				cn++;
				for(int j=1;j<i;j++){
					//cout<<"POP "<<cn<<" GOTO "<<cn-1<<"; PUSH "<<cn<<" GOTO "<<end<<"\n";
					ans.push_back({cn,cn-1,cn,end});
				    cn++;
				}
				break;
			}
		}
		n=(1LL<<i)+1-n;
		for(int j=i;j>=0;j--){
			if(n>=(1LL<<j)){
				ans[j].y--;
				n-=(1LL<<j);
			}
		}
	}
	cout<<cn<<"\n";
	for(auto i:ans){
		cout<<"POP "<<i.a<<" GOTO "<<i.x<<"; PUSH "<<i.b<<" GOTO "<<i.y<<"\n";
	}
    cout<<"HALT; PUSH 1 GOTO 1\n";
	return 0;
}