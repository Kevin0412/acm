#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class SegmentTree{
public:
    int n;
    vector<ll> tree;
    vector<ll> lazy;

    void build(const vector<ll> &arr, int node, int start, int end){
        if(start==end){
            tree[node]=arr[start];
            return;
        }
        int mid=(start+end)/2;
        int left_node=node*2+1;
        int right_node=node*2+2;
        build(arr, left_node, start, mid);
        build(arr, right_node, mid+1, end);
        tree[node]=max(tree[left_node],tree[right_node]);
    }

    void push_down(int node, int start, int end){
        if(lazy[node]!=0){
            int mid=(start+end)/2;
            int left_node=node*2+1;
            int right_node=node*2+2;
            tree[left_node]+=lazy[node];
            tree[right_node]+=lazy[node];
            lazy[left_node]+=lazy[node];
            lazy[right_node]+=lazy[node];

            lazy[node]=0;
        }
    }

    void update_range(int node, int start,int end,int l,int r,ll val){
        if(l <= start && end <= r){
            tree[node]+=val;
            lazy[node]+=val;
            return;
        }

        push_down(node,start,end);
        int mid=(start+end)/2;
        int left_node=2*node+1;
        int right_node=2*node+2;

        if(l<=mid) update_range(left_node,start,mid,l,r,val);
        if(r>mid) update_range(right_node,mid+1,end,l,r,val);

        tree[node]=max(tree[left_node],tree[right_node]);
    }

    ll query_range(int node,int start,int end,int l,int r){
        if(r<start || end<l) return 0;
        if(l<=start && end<=r) return tree[node];

        push_down(node,start,end);
        int mid=(start+end)/2;
        int left_node=2*node+1;
        int right_node=2*node+2;

        ll left_max=query_range(left_node,start,mid,l,r);
        ll right_max=query_range(right_node,mid+1,end,l,r);
        return max(left_max,right_max);
    }

    SegmentTree(const vector<long long>& arr){
        n=arr.size();
        tree.resize(4*n,0);
        lazy.resize(4*n,0);
        build(arr,0,0,n-1);
    }

    void update(int l,int r,ll val){
        update_range(0,0,n-1,l,r,val);
    }

    ll query(int l,int r){
        return query_range(0,0,n-1,l,r);
    }
};

void solve(){
    int n,k,x,y;
    cin>>n>>k;
    vector<pair<int,int>> a;
    queue<pair<int,int>> q;
    vector<ll> arr(n+1,0);
    SegmentTree st(arr);
    for(int i=0;i<n;i++){
        cin>>x>>y;
        a.push_back({x-1,y-1});
    }
    int ans=0;

    int l=0;
    for(int r=0;r<n;r++){
        q.push(a[r]);
        st.update(a[r].first,a[r].second,1);
        while(st.query(0,n)>k){
            st.update(a[l].first,a[l].second,-1);
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T-->0){
        solve();
    }

    // int m,n,q,x,y,i;
    // cin>>n>>m;
    // vector<ll> arr;
    // ll a,k;
    // for(i=0;i<n;i++){
    //     cin>>a;
    //     arr.push_back(a);
    // }
    // SegmentTree st(arr);

    // for(i=0;i<m;i++){
    //     cin>>q>>x>>y;
    //     if(q==1){
    //         cin>>k;
    //         st.update(x-1,y-1,k);
    //     }else{
    //         cout<<st.query(x-1,y-1)<<"\n";
    //     }
    // }

    return 0;
}