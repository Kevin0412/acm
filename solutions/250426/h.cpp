#include <bits/stdc++.h>

using namespace std;

struct d {
	int n;
	int y;
};

struct CompareMin {
    bool operator()(const d& a1, const d& a2) {
        return a1.y > a2.y;
    }
};

int main() {
    priority_queue<d, vector<d>, CompareMin> pq;
    int n,m;
    
    cin>>n>>m;
    int a[n],b[n],c[n],x[n];
    
    for(int i=0;i<n;i++){
    	cin>>a[i]>>b[i]>>c[i];
    	x[i]=1;
    	pq.push({i,a[i]+b[i]+c[i]});
    }
    
    for(int i=0;i<m;i++){
    	d e=pq.top();
    	cout<<e.y<<" ";
    	pq.pop();
    	x[e.n]++;
    	pq.push({e.n,a[e.n]*x[e.n]*x[e.n]+b[e.n]*x[e.n]+c[e.n]});
    }

    return 0;
}