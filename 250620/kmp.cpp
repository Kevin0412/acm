#include <vector>
#include <string>
using namespace std;

// KMP算法模板函数
// 输入：文本串text，模式串pattern
// 输出：返回pattern在text中首次出现的下标（从0开始），未找到返回-1
int kmp(const string& text, const string& pattern) {
    int n = text.size(), m = pattern.size();
    if (m == 0) return 0;  // 空模式串匹配位置0
    if (n < m) return -1;  // 文本长度小于模式，不可能匹配

    // 1. 构建next数组（前缀函数）
    vector<int> next(m, 0);
    // j表示当前匹配的前缀长度，也即最长公共前后缀长度
    for (int i = 1, j = 0; i < m; i++) {
        // 不匹配时回退到前一个匹配位置
        while (j > 0 && pattern[i] != pattern[j])
            j = next[j - 1];
        // 匹配时前缀长度+1
        if (pattern[i] == pattern[j])
            j++;
        next[i] = j;  // 记录当前位置的最长公共前后缀长度
    }

    // 2. 使用next数组进行模式匹配
    for (int i = 0, j = 0; i < n; i++) {
        // 不匹配时利用next数组跳过部分字符
        while (j > 0 && text[i] != pattern[j])
            j = next[j - 1];
        // 当前字符匹配成功
        if (text[i] == pattern[j])
            j++;
        // 完全匹配模式串
        if (j == m)
            return i - m + 1;  // 返回起始位置
    }
    return -1;  // 未找到匹配
}
