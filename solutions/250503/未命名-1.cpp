#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

inline bool compare(const string& a, const string& b) noexcept {
    const size_t a_len = a.size(), b_len = b.size();
    const size_t total = a_len + b_len;
    size_t i = 0;
    
    while (i < total) {
        // 计算 a+b 在 i 位置的字符
        const char ca = (i < a_len) ? a[i] : b[i - a_len];
        // 计算 b+a 在 i 位置的字符
        const char cb = (i < b_len) ? b[i] : a[i - b_len];
        
        if (ca < cb) return true;
        if (ca > cb) return false;
        
        ++i;
    }
    return false; // 完全相等
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<string> strs;
    strs.reserve(n);
    
    string s;
    while (n--) {
        cin >> s;
        strs.emplace_back(move(s));
    }
    
    sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
        return compare(a, b);
    });
    
    string result;
    result.reserve(2e7); // 预分配内存
    
    for (const auto& str : strs) {
        result += str;
    }
    
    cout << result;
    return 0;
}