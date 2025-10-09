#include<bits/stdc++.h>
#define int long long
using namespace std;

class ST {
private:
    vector<vector<int>> st;
    vector<int> log;
    
public:
    ST(vector<int>& arr) {
        int n = arr.size();
        log.resize(n + 1);
        for (int i = 2; i <= n; i++) log[i] = log[i / 2] + 1;
        
        int k = log[n] + 1;
        st.resize(n, vector<int>(k));
        
        for (int i = 0; i < n; i++) st[i][0] = arr[i];
        for (int j = 1; j < k; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    
    int query(int l, int r) {
        int j = log[r - l + 1];
        return max(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

signed main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	int n,m;
	n=read();
	m=read();
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		arr[i]=read();
	}
	ST st(arr);
	vector<int> ans;
	for(int i=0;i<m;i++){
		int l,r;
		l=read();
		r=read();
		ans.push_back(st.query(l-1,r-1));
	}
	for(auto i:ans){
		cout<<i<<"\n";
	}
	return 0;
}