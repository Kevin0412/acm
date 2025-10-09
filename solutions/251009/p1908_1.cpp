#include<bits/stdc++.h>
#define int long long
using namespace std;

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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SortWithSwapCount sorter;
    cout<<sorter.sortAndCountSwaps(arr)<<"\n";
    return 0;
}