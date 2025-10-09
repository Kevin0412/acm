#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6+6;

struct node{
    int l,r,id,index;
};
int cntEle[N];//确保最值包含
vector<int> arr;
vector<int> ans;
int len;
int sum;//统计重复出现元素的种类个数
void move(int pos,int sign){//考虑左右端点 左移右移 带来的统计变化
    if(sign==1){//新加元素
        if(cntEle[arr[pos]]==0) sum++;//重复出现
        cntEle[arr[pos]]++;
    }else{//退出元素
        cntEle[arr[pos]]--;
        if(cntEle[arr[pos]]==0) sum--;//变为单独出现
    }
}
bool cmp(const node& x,const node& y){//左端点在同一奇数块的区间，右端点按升序排列，反之降序。
    return (x.index^y.index) ? x.index<y.index : (x.index& 1 ) ? x.r<y.r:x.r>y.r; 
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,q;
    cin>>n;
    len=(int) sqrt(n);
    arr.resize(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>q;
    vector<node> query(q);
    for(int i=0;i<q;i++){
        cin>>query[i].l>>query[i].r;
        query[i].l--;query[i].r--;
        query[i].id=i;
        query[i].index=query[i].l/len;
    }
    sort(query.begin(),query.end(),cmp);
    ans.clear();ans.resize(q,0);
    for(int i=0,l=0,r=-1;i<q;i++){//调整区间
        while (l > query[i].l) move(--l, 1);
        while (r < query[i].r) move(++r, 1);
        while (l < query[i].l) move(l++, -1);
        while (r > query[i].r) move(r--, -1);
        ans[query[i].id]=sum;
    }
    for(int i=0;i<q;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}