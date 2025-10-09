#include<bits/stdc++.h>

using namespace std;

vector<int> pattern_next(const string& pattern){
    int m = pattern.size();
    vector<int> next(m, 0);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j])
            j = next[j - 1];
        if (pattern[i] == pattern[j])
            j++;
        next[i] = j;
    }
    return next;
}

vector<int> kmp(const string& text, const string& pattern, vector<int> next) {
	vector<int> ans;
    int n = text.size(), m = pattern.size();
    //if (m == 0) return 0;
    if (n < m) return ans;

    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j])
            j = next[j - 1];
        if (text[i] == pattern[j])
            j++;
        if (j == m)
            ans.push_back(i - m + 1);
    }
    return ans;
}

void solve(){
	int n,m;
	cin>>n>>m;
	string text,pattern;
	cin>>text>>pattern;
	vector<int> a=kmp(text,pattern,pattern_next(pattern));
	if(a.empty()){
		cout<<0<<endl;
		return;
	}
	vector<int> ans;
	ans.push_back(a[0]+m-1);
	for(auto i:a){
		if(i>ans[ans.size()-1]){
			ans.push_back(i+m-1);
		}
	}
	cout<<ans.size()<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}