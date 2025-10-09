#include<bits/stdc++.h>

using namespace std;

void solve(){
	string s;
	cin>>s;
	int i,a[26],j;
	for(i=0;i<26;i++)a[i]=0;
	for(i=0;i<s.length();i++){
		a[s[i]-'A']++;
	}
	for(i=0;i<a[19];i++){
		cout<<"T";
	}
	for(i=0;i<26;i++){
		if(i==19)continue;
		for(j=0;j<a[i];j++){
			printf("%c",'A'+i);
		}
	}
	cout<<endl;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}