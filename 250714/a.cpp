#include<bits/stdc++.h>

using namespace std;

int main(){
	unordered_map<long long,long long> ump;
	int n,i;
	long long c,ans=0;
	cin>>n>>c;
	long long a;
	for(i=0;i<n;i++){
		cin>>a;
		ump[a]++;
	}
	for (const auto& pair : ump) {
		long long target = pair.first + c;
        auto it = ump.find(target);
        if (it != ump.end()) {
            ans += pair.second * it->second;
        }
    }
    cout<<ans<<endl;
    return 0;
	}