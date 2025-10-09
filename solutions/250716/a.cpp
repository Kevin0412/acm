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

int main(){
	string text,pattern;
	cin>>text>>pattern;
	vector<int> next=pattern_next(pattern);
	vector<int> ans=kmp(text,pattern,next);
	for(auto i:ans)cout<<i+1<<endl;
	for(auto i:next)cout<<i<<" ";
	cout<<endl;
	return 0;
}