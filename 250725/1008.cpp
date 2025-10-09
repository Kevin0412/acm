#include <bits/stdc++.h>
using namespace std;

inline long long read() {
    long long x = 0;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x;
}

char s[1000006];

void solve() {
    int n=read(),ans1=0,ans2=0;
    vector<int> l;
    scanf("%s",s);
    for(int i=0;i<n;i++){
    	if(s[i]==s[(i+1)%n]){
    		l.push_back(i);
    	}
    }
    //for(int i=0;i<l.size();i++)cerr<<l[i]<<" ";
    //cerr<<endl;
    for(int i=0;i<l.size();i+=2){
		ans1+=(l[i+1]-l[i]+1)/2;
		if(i+2!=l.size())ans2+=(l[i+2]-l[i+1]+1)/2;
		else ans2+=(l[0]-l[i+1]+1+n)/2;
		//cerr<<ans1<<" "<<ans2<<endl;
    }
    printf("%d\n",min(ans1,ans2));
}

int main() {
    int t = read();
    while (t--) {
        solve();
    }
    return 0;
}