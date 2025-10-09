#include<bits/stdc++.h>
using namespace std;

long long MOD=998244353;

int getidx(char ch){
	return ch-'a';
}

struct trie {
	int nex[1000006][26], cnt;
	long long pass[1000006];
	int endp[1000006];
	
	void insert(string s){
		int p=0;
		pass[p]++;
		for(int i=0;i<s.length();i++){
			int c=getidx(s[i]);
			if(!nex[p][c]){
				nex[p][c]= ++cnt;
				for(int j=0;j<26;j++){
					nex[cnt][j]=0;
				}
				pass[cnt]=0;
				endp[cnt]=0;
			}
			p=nex[p][c];
			pass[p]++;
		}
		endp[p]++;
	}
	
	void clear(){
		for(int j=0;j<26;j++){
			nex[0][j]=0;
		}
		pass[0]=0;
		endp[0]=0;
		cnt=0;
	}
};

trie a;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int i,n;
	cin>>n;
	a.clear();
	string s;
	for(i=0;i<n;i++){
		cin>>s;
		a.insert(s);
	}
	long long ans=0;
	for(i=1;i<=a.cnt;i++){
		ans+=a.pass[i]*a.pass[i];
		ans%=MOD;
	}
	
	cout<<ans<<"\n";
	
	return 0;
}