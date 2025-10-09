#include<bits/stdc++.h>  
using namespace std;  
  
struct Node {  
    int count; // 存储的是计数，而不是原始值  
    int left_child_idx;  
    int right_child_idx;  
  
    explicit Node(int cnt = 0, int lc = 0, int rc = 0) : count(cnt), left_child_idx(lc), right_child_idx(rc) {}  
};  
  
class PersistentSegmentTree {  
private:  
    std::vector<Node> tree_nodes;  
    std::vector<int> roots; // roots[i] 存储的是考虑了前 i 个元素后的权值线段树的根  
    int next_node_idx;  
    int value_range_size; // 离散化后的值域大小  
  
    // 构建一个空的线段树，所有计数为 0    
    int build_empty_tree(const int l, const int r) {  
        const int current_node_idx = next_node_idx++;  
        if (l == r) {  
            tree_nodes[current_node_idx].count = 0; // 初始计数为0  
            return current_node_idx;  
        }  
  
        const int mid = l + (r - l) / 2;  
        tree_nodes[current_node_idx].left_child_idx = build_empty_tree(l, mid);  
        tree_nodes[current_node_idx].right_child_idx = build_empty_tree(mid + 1, r);  
        tree_nodes[current_node_idx].count = 0; // 空树总和为0  
        return current_node_idx;  
    }  
  
    // 更新操作：在权值线段树中，将离散化后的值 p 的计数增加 c (这里 c 通常是 1)    
    int update(int prev_node_idx, int l, int r, int p, int c_val) {  
        int current_node_idx = next_node_idx++;  
        tree_nodes[current_node_idx] = tree_nodes[prev_node_idx]; // 复制旧节点信息  
  
        // 仅增加当前节点的 count        
        tree_nodes[current_node_idx].count += c_val;  
  
        if (l == r) {  
            return current_node_idx;  
        }  
  
        int mid = l + (r - l) / 2;  
        if (p <= mid) {  
            tree_nodes[current_node_idx].left_child_idx = update(tree_nodes[prev_node_idx].left_child_idx, l, mid, p, c_val);  
        } else {  
            tree_nodes[current_node_idx].right_child_idx = update(tree_nodes[prev_node_idx].right_child_idx, mid + 1, r, p, c_val);  
        }  
        return current_node_idx;  
    }  
  
    // 查询区间 [left_root, right_root] 的第 k 小值  
    // l, r 是当前节点代表的值域区间  
    int query_kth(int left_root_idx, int right_root_idx, int l, int r, int k) {  
        if (l == r) {  
            return l; // 返回离散化后的值域下标  
        }  
  
        // 计算左子树在 right_root 中的总数  
        int count_in_right_left = tree_nodes[tree_nodes[right_root_idx].left_child_idx].count;  
        // 计算左子树在 left_root 中的总数  
        int count_in_left_left = tree_nodes[tree_nodes[left_root_idx].left_child_idx].count;  
  
        // 区间 [l, r] 中，左子树（值域 [l, mid]）内的元素数量  
        int count_in_current_left_subtree = count_in_right_left - count_in_left_left;  
  
        int mid = l + (r - l) / 2;  
        if (k <= count_in_current_left_subtree) {  
            // 第 k 小值在左子树中  
            return query_kth(tree_nodes[left_root_idx].left_child_idx, tree_nodes[right_root_idx].left_child_idx, l, mid, k);  
        } else {  
            // 第 k 小值在右子树中，k 减去左子树中的数量  
            return query_kth(tree_nodes[left_root_idx].right_child_idx, tree_nodes[right_root_idx].right_child_idx, mid + 1, r, k - count_in_current_left_subtree);  
        }  
    }  
  
  
public:  
    // N 这里代表的是离散化后的值域大小，而不是原始数组的长度  
    explicit PersistentSegmentTree(int _value_range_size) :  
        value_range_size(_value_range_size),  
        tree_nodes(4500000 + 5), // 估算节点数量，每个版本增加 logN 个节点  
        next_node_idx(1)  
    {  
        roots.reserve(200005); // N+M 个版本  
    }  
  
    // 提供给外部调用的 build_empty_tree    
    int build_empty_tree_public() {  
        return build_empty_tree(1, value_range_size);  
    }  
  
    // 提供给外部调用的 update    
    int update_public(int prev_root_idx, int p, int c) {  
        return update(prev_root_idx, 1, value_range_size, p, c);  
    }  
  
    // 提供给外部调用的 query_kth    
    int query_kth_public(int l_root_idx, int r_root_idx, int k) {  
        return query_kth(l_root_idx, r_root_idx, 1, value_range_size, k);  
    }  
  
    // 暴露 roots 向量以便外部直接管理版本  
    std::vector<int>& get_roots() {  
        return roots;  
    }  
};  
  
int main() {  
    std::ios_base::sync_with_stdio(false);  
    std::cin.tie(NULL);  
    int N, M, K;  
    std::cin >> N >> M >> K;  
  
    std::vector<int> initial_array(N);  
    std::vector<int> all_values; // 收集所有值用于离散化  
    for (int i = 0; i < N; ++i) {  
        std::cin >> initial_array[i];  
        all_values.push_back(initial_array[i]);  
    }  
  
    // 离散化  
    sort(all_values.begin(), all_values.end());  
    all_values.erase(unique(all_values.begin(), all_values.end()), all_values.end());  
  
    // 离散化后的值域大小  
    int distinct_values_count = all_values.size();  
  
    PersistentSegmentTree pst(distinct_values_count);  
  
    // roots[0] 为空树的根  
    pst.get_roots().push_back(pst.build_empty_tree_public());  
  
    // 构建 N 个版本  
    for (int i = 0; i < N; ++i) {  
        // 找到 initial_array[i] 在 all_values 中的离散化下标 (1-indexed)        
        int discretized_idx = lower_bound(all_values.begin(), all_values.end(), initial_array[i]) - all_values.begin() + 1;  
        // 从上一个版本更新，将 discretized_idx 位置的计数加 1        
        pst.get_roots().push_back(pst.update_public(pst.get_roots().back(), discretized_idx, 1));  
    }  
    
    vector<long long> k_min;
    for (int i = 0; i < N-M+1; ++i) {  
        // 查询版本 roots[r] 和 roots[l-1] 之间的第 k 小值  
        int result_discretized_idx = pst.query_kth_public(pst.get_roots()[i], pst.get_roots()[i+M], K);  
        // 将离散化后的结果转换回原始值并输出 (注意 all_values 是 0-indexed)        
        //cerr << all_values[result_discretized_idx - 1] << " ";  
        k_min.push_back(all_values[result_discretized_idx - 1]);
    }  
    //cerr<<endl;
    vector<long long> a;
    for(int i=0;i<M;i++){
    	a.push_back(initial_array[i]);
    }
    sort(a.begin(),a.end());
    long long sum=0;
    for(int i=0;i<K;i++){
    	sum+=a[i];
    }
    cout<<sum<<" ";
    for(int i=1;i< N-M+1;i++){
    	if(initial_array[i-1]<=k_min[i-1]){
    		sum-=initial_array[i-1];
    		//cerr<<initial_array[i-1]<<" ";
    	}else{
    		sum-=k_min[i-1];
    		//cerr<<k_min[i-1]<<" ";
    	}if(initial_array[i+M-1]<=k_min[i]){
    		sum+=initial_array[i+M-1];
    		//cerr<<initial_array[i+M-1]<<endl;
    	}else{
    		sum+=k_min[i];
    		//cerr<<k_min[i]<<endl;
    	}
    	cout<<sum<<" ";
    }
    cout<<"\n";
  
    return 0;  
}