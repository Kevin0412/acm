#include <iostream>
#include <string>
#include <vector>

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

int kmp(const string& text, const string& pattern, vector<int> next) {
    int n = text.size(), m = pattern.size();
    //if (m == 0) return 0;
    if (n < m) return -1;

    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j])
            j = next[j - 1];
        if (text[i] == pattern[j])
            j++;
        if (j == m)
            return i - m + 1;
    }
    return -1;
}

int main(){
    int i,t,n,j,d;
    string a,b1,b2,c;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        cin>>a>>c;
	vector<int> c_next=pattern_next(c);
	d=0;
        for(j=1;j<=n;j++){
            cin>>b1>>b2;
            if(kmp(b2,c,c_next)>=0){
	        if(kmp(a,b1,pattern_next(b1))>=0){
		    if(d){
		        cout<<" ";
		    }
		    d=1;
		    cout<<j;
		}
            }
        }
        cout<<endl;
    }
    return 0;
}
