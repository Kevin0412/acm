#include<bits/stdc++.h>
#define int long long
using namespace std;

class SegmentTree{
    private:
    int n;
    vector<int> tree;
    vector<int> lazy;

    void build(const vector<long long>& arr, int node,int start,int end){
        if(start ==end){
            tree[node] = arr[start];
            return;
        }
        int mid=(start +end)/2;
        int left_node=2*node+1;
        int right_node=2*node +2;
        build(arr, left_node,start,mid);
        build(arr, right_node,mid + 1, end);
        tree[node] = min(tree[left_node],tree[right_node]);
    }

    void push_down(int node,int start,int end){
        if (lazy[node]!=0){
            int mid = (start+end)/2;
            int left_node = 2*node +1;
            int right_node =2*node+2;

            tree[left_node]+=lazy[node];
            tree[right_node]+=lazy[node];
            lazy[left_node]+=lazy[node];
            lazy[right_node] +=lazy[node];

            lazy[node]=0;
        }
    }

    void update_range(int node, int start,int end,int l,int r, int val){
        if (l<=start && end <=r){
            tree[node]+=val*(end-start+1);
            lazy[node]+=val;
            return;
        }

        push_down(node,start,end);
        int mid = (start+end)/2;
        int left_node = 2*node +1;
        int right_node =2*node+2;

        if(l <=mid) update_range(left_node,start,mid,l,r,val);
        if(r>mid) update_range(right_node,mid+1,end,l,r,val);

        tree[node] = min(tree[left_node],tree[right_node]);
    }

    int query_range(int node,int start,int end,int l,int r){
        if(r<start || end<l) return (int)1e20;
        if(l <=start && end<=r) return tree[node];

        push_down(node,start,end);
        int mid = (start+end)/2;
        int left_node = 2*node +1;
        int right_node =2*node+2;

        int left_min=query_range(left_node,start,mid,l,r);
        int right_min=query_range(right_node,mid+1,end,l,r);
        return min(left_min,right_min);
    }

    public:
    SegmentTree(const vector<long long>& arr){
        n=arr.size();
        tree.resize(4*n,0);
        lazy.resize(4*n,0);
        build(arr,0,0,n-1);
    }

    void update(int l,int r,int val){
        update_range(0,0,n-1,l,r,val);
    }

    int query(int l,int r){
        return query_range(0,0,n-1,l,r);
    }
};


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<pair<int,int>> wr(m,{0,0});
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    unordered_map<int,priority_queue<int, vector<int>, greater<int>>> b;
    for(int i=0;i<n;i++){
        if(b.count(a[i])==0){
            priority_queue<int, vector<int>, greater<int>> pq;
            b[a[i]]=pq;
        }
        b[a[i]].push(i);
    }
    for(int i=0;i<m;i++){
        cin>>wr[i].second>>wr[i].first;
    }
    sort(wr.begin(),wr.end(),[](auto a,auto b){
        if(a.second==b.second){
            return a.first>b.first;
        }
        return a.second<b.second;
    });
    SegmentTree st(a);
    for(int i=0;i<m;i++){
        int c=st.query(0,wr[i].second-1);
        st.update(b[c].top(),b[c].top(),-wr[i].first);
        if(b.count(c-wr[i].first)==0){
            priority_queue<int, vector<int>, greater<int>> pq;
            b[c-wr[i].first]=pq;
        }
        b[c-wr[i].first].push(b[c].top());
        b[c].pop();
    }
    vector<int> d;
    for(int i=0;i<n;i++){
        d.push_back(st.query(i,i));
    }
    sort(d.begin(),d.end());
    int ans=0;
    for(auto i:d){
        ans+=i;
        cout<<ans<<" ";
    }
    cout<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}