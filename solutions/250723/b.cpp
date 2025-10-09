#include <vector>
#include <iostream>
using namespace std;

class SegmentTree {
private:
    int n;  // 原始数组大小
    vector<long long> tree;  // 线段树数组
    vector<long long> add;   // 加法懒惰标记
    vector<long long> mul;   // 乘法懒惰标记（初始化为1）
    
    // 下推懒惰标记
    void push_down(int node, int start, int end) {
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        int left_len = mid - start + 1;
        int right_len = end - mid;
        
        // 更新左子树
        if (left_node < tree.size()) {
            // 先乘后加：值 = 原值 * mul + add * 区间长度
            tree[left_node] = tree[left_node] * mul[node] + add[node] * left_len;
            // 更新左子树的懒惰标记：先乘后加
            mul[left_node] *= mul[node];
            add[left_node] = add[left_node] * mul[node] + add[node];
        }
        
        // 更新右子树
        if (right_node < tree.size()) {
            tree[right_node] = tree[right_node] * mul[node] + add[node] * right_len;
            mul[right_node] *= mul[node];
            add[right_node] = add[right_node] * mul[node] + add[node];
        }
        
        // 重置当前节点标记
        mul[node] = 1;
        add[node] = 0;
    }
    
    // 构建线段树
    void build(const vector<long long>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        build(arr, left_node, start, mid);
        build(arr, right_node, mid + 1, end);
        tree[node] = tree[left_node] + tree[right_node];
    }
    
    // 区间乘法更新
    void update_mul(int node, int start, int end, int l, int r, long long c) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            // 更新当前节点值
            tree[node] = tree[node] * c;
            // 更新乘法标记（影响后续操作）
            mul[node] *= c;
            // 加法标记也需要乘以c
            add[node] *= c;
            return;
        }
        push_down(node, start, end);
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        update_mul(left_node, start, mid, l, r, c);
        update_mul(right_node, mid + 1, end, l, r, c);
        tree[node] = tree[left_node] + tree[right_node];
    }
    
    // 区间加法更新
    void update_add(int node, int start, int end, int l, int r, long long d) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            // 更新当前节点值
            tree[node] += d * (end - start + 1);
            // 更新加法标记
            add[node] += d;
            return;
        }
        push_down(node, start, end);
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        update_add(left_node, start, mid, l, r, d);
        update_add(right_node, mid + 1, end, l, r, d);
        tree[node] = tree[left_node] + tree[right_node];
    }
    
    // 区间求和查询
    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        
        push_down(node, start, end);
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        long long left_sum = query(left_node, start, mid, l, r);
        long long right_sum = query(right_node, mid + 1, end, l, r);
        return left_sum + right_sum;
    }

public:
    SegmentTree(const vector<long long>& arr) {
        n = arr.size();
        tree.resize(4 * n, 0);
        add.resize(4 * n, 0);
        mul.resize(4 * n, 1);  // 乘法标记初始化为1
        build(arr, 0, 0, n - 1);
    }
    
    // 区间乘法：将区间[l, r]乘以c
    void multiply(int l, int r, long long c) {
        update_mul(0, 0, n - 1, l, r, c);
    }
    
    // 区间加法：将区间[l, r]加上d
    void addVal(int l, int r, long long d) {
        update_add(0, 0, n - 1, l, r, d);
    }
    
    // 区间求和：求区间[l, r]的和
    long long sum(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

// 测试示例
int main() {
	int m,n,q,x,y,i;
	cin>>n>>m;
    vector<long long> arr;
    long long a,k;
    for(i=0;i<n;i++){
    	cin>>a;
    	arr.push_back(a);
    }
    SegmentTree st(arr);
    
    for(i=0;i<m;i++){
    	cin>>q>>x>>y;
    	if(q==1){
    		cin>>k;
    		st.update(x-1,y-1,k);
    	}else{
    		cout<<st.query(x-1,y-1)<<endl;
    	}
    }

    return 0;
    vector<long long> arr = {1, 2, 3, 4, 5};
    SegmentTree st(arr);
    
    // 初始状态
    cout << "初始区间和: " << st.sum(0, 4) << endl;  // 15
    
    // 区间[0,2]乘以2 -> [2,4,6,4,5]
    st.multiply(0, 2, 2);
    cout << "乘以2后区间和: " << st.sum(0, 4) << endl;  // 2+4+6+4+5=21
    
    // 区间[0,2]加上3 -> [5,7,9,4,5]
    st.addVal(0, 2, 3);
    cout << "加上3后区间和: " << st.sum(0, 4) << endl;  // 5+7+9+4+5=30
    
    // 区间[3,4]乘以3 -> [5,7,9,12,15]
    st.multiply(3, 4, 3);
    cout << "最后区间和: " << st.sum(0, 4) << endl;  // 5+7+9+12+15=48
    
    return 0;
}