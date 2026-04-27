#include<bits/stdc++.h>

using namespace std;
#define ll long long

class SortWithSwapCount {
private:
    long long swapCount;  // 统计交换次数

    // 归并排序的合并过程
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                // 当左半部分的元素大于右半部分的元素时
                // 需要将右半部分的元素移动到左半部分元素的前面
                // 这相当于进行了 (mid - i + 1) 次相邻交换
                swapCount += (mid - i + 1);
                temp[k++] = arr[j++];
            }
        }
        
        // 复制剩余元素
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= right) {
            temp[k++] = arr[j++];
        }
        
        // 将临时数组复制回原数组
        for (int idx = 0; idx < k; idx++) {
            arr[left + idx] = temp[idx];
        }
    }

    // 归并排序递归函数
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

public:
    SortWithSwapCount() : swapCount(0) {}
    
    // 排序并返回交换次数
    long long sortAndCountSwaps(vector<int>& arr) {
        swapCount = 0;
        if (arr.size() <= 1) return 0;
        
        mergeSort(arr, 0, arr.size() - 1);
        return swapCount;
    }
};

void solve() {
    int n;
    cin>>n;
    string ans;
    vector<int>a(n+1),b(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i];
   // vector<int>a1(n+1);
    vector<int>b1(n+1);
    for(int i=1;i<=n;++i){
    	//a1[a[i]]=i;
    	b1[b[i]]=i;
    }
    vector<int> c(n);
    for(int i=1;i<=n;++i){
    	c[i-1]=b1[a[i]];
    	//cerr<<c[i]<<" ";
    }
    //int cnt=0;//for(int i=1;i<=n;++i)cnt+=abs(a1[i]-b1[i]);
    SortWithSwapCount sorter;
    int cnt = sorter.sortAndCountSwaps(c);
    
    if(cnt%2==0) ans+='B';else ans+='A';
    //if(cnt==0) ans[0]='B';
    cout<<ans;
    for(int i=1;i<=n-1;++i) {
        char tmp;
        int l,r,d;
        cin>>tmp>>l>>r>>d;
        d%=(r-l+1);
        int k=((d%2)*((r-l+1-d)%2))%2;
        if(k){
        	if(ans[0]=='A')ans[0]='B';
        	else ans[0]='A';
        }
        cout<<ans;
    }
    cout<<"\n";

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }

    return 0;
}