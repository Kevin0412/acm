#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
    map<int,int> *mp;  // 保持指针类型，实现启发式合并
    int zeros;
    int parent;
    vector<int> sons;
};

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++){
        a[i]=a[i]*2;
        b[i]=b[i]*2+1;
    }
    
    vector<node> tree(n+1);
    for(int i=0;i<=n;i++){
        tree[i].zeros=0;
        tree[i].parent=0;
        tree[i].mp = new map<int, int>();  // 初始分配
    }
    
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        tree[u].sons.push_back(v);
        tree[v].sons.push_back(u);
    }
    
    // 构建父节点关系
    vector<int> bfs;
    bfs.push_back(1);
    while(!bfs.empty()){
        int k=bfs.back();
        bfs.pop_back();
        for(auto i:tree[k].sons){
            if(i!=tree[k].parent){
                tree[i].parent=k;
                bfs.push_back(i);
            }
        }
    }
    
    // 后序遍历处理
    vector<int> visited(n+1,0);
    vector<int> ans(n+1,0);
    vector<int> dfs;
    dfs.push_back(1);
    
    while(!dfs.empty()){
        int k=dfs.back();
        
        // 先压入未访问的子节点
        bool has_unvisited_child = false;
        for(auto i:tree[k].sons){
            if(i!=tree[k].parent && !visited[i]){
                dfs.push_back(i);
                has_unvisited_child = true;
            }
        }
        if(has_unvisited_child) continue;
        
        visited[k] = 1;
        dfs.pop_back();
        
        // 收集子节点信息
        int max_size = -1;
        node* max_child = nullptr;
        
        for(auto i:tree[k].sons){
            if(i!=tree[k].parent){
                tree[k].zeros += tree[i].zeros;
                // 找到最大的子节点map
                if((int)tree[i].mp->size() > max_size){
                    max_size = tree[i].mp->size();
                    max_child = &tree[i];
                }
            }
        }
        
        // 启发式合并：如果有子节点，复用最大的map
        if(max_child != nullptr){
            tree[k].mp = max_child->mp;  // 复用最大子节点的map
        }
        
        // 合并其他子节点到当前map
        for(auto i:tree[k].sons){
            if(i!=tree[k].parent && &tree[i] != max_child){  // 只合并非最大的子节点
                for(const auto& [key, value] : *(tree[i].mp)){
                    if(value != 0){
                        (*(tree[k].mp))[key] += value;
                        
                        // 处理配对逻辑（与第二段代码完全一致）
                        if(key % 2 == 0){
                            if((*(tree[k].mp)).count(key+1)){
                                int l = min((*(tree[k].mp))[key], (*(tree[k].mp))[key+1]);
                                (*(tree[k].mp))[key] -= l;
                                (*(tree[k].mp))[key+1] -= l;
                            }
                        }else{
                            if((*(tree[k].mp)).count(key-1)){
                                int l = min((*(tree[k].mp))[key], (*(tree[k].mp))[key-1]);
                                (*(tree[k].mp))[key] -= l;
                                (*(tree[k].mp))[key-1] -= l;
                            }
                        }
                    }
                }
                // 清理已合并的map
                (*(tree[i].mp)).clear();
                delete tree[i].mp;
                tree[i].mp = nullptr;
            }
        }
        
        // 处理当前节点的a[k]和b[k]（与第二段代码完全一致）
        if(a[k] == 0){
            tree[k].zeros++;
        }else{
            (*(tree[k].mp))[a[k]]++;
            if((*(tree[k].mp)).count(a[k]+1)){
                int l = min((*(tree[k].mp))[a[k]], (*(tree[k].mp))[a[k]+1]);
                (*(tree[k].mp))[a[k]] -= l;
                (*(tree[k].mp))[a[k]+1] -= l;
            }
        }
        
        if(b[k] == 1){
            tree[k].zeros++;
        }else{
            (*(tree[k].mp))[b[k]]++;
            if((*(tree[k].mp)).count(b[k]-1)){
                int l = min((*(tree[k].mp))[b[k]], (*(tree[k].mp))[b[k]-1]);
                (*(tree[k].mp))[b[k]] -= l;
                (*(tree[k].mp))[b[k]-1] -= l;
            }
        }
        
        // 计算答案
        int sum = -tree[k].zeros;
        for(const auto& [key, value] : *(tree[k].mp)){
            sum += value;
        }
        ans[k] = (sum <= 0) ? 1 : 0;
    }
    
    for(int i=1;i<=n;i++){
        cout<<ans[i];
    }
    cout<<"\n";
    
    // 清理根节点内存
    delete tree[1].mp;
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