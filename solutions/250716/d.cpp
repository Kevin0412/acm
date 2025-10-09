#include<bits/stdc++.h>

using namespace std;

int getidx(char ch) {
    if (ch >= 'a' && ch <= 'z') return ch - 'a';
    else if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 26;
    else return ch - '0' + 52;
}

struct trie {
    int nex[3000001][62], cnt;
    int pass[3000001];
    int endp[3000001];
    
    void insert(string s) {
        int p = 0; // 从根节点0开始
        pass[p]++;
        for (int i = 0; i < s.length(); i++) {
            int c = getidx(s[i]);
            if (!nex[p][c]) {
                nex[p][c] = ++cnt;
                // 初始化新节点
                for (int j = 0; j < 62; j++) {
                    nex[cnt][j] = 0;
                }
                pass[cnt] = 0;
                endp[cnt] = 0;
            }
            p = nex[p][c];
            pass[p]++;
        }
        endp[p]++;
    }
    
    int search_whole_s(string s) {
        int p = 0;
        for (int i = 0; i < s.length(); i++) {
            int c = getidx(s[i]);
            if (!nex[p][c]) return 0;
            p = nex[p][c];
        }
        return endp[p];
    }
    
    int search_prefix_s(string s) {
        int p = 0;
        for (int i = 0; i < s.length(); i++) {
            int c = getidx(s[i]);
            if (!nex[p][c]) return 0;
            p = nex[p][c];
        }
        return pass[p];
    }
    
    void clear() {
        // 重置根节点0
        for (int j = 0; j < 62; j++) {
            nex[0][j] = 0;
        }
        pass[0] = 0;
        endp[0] = 0;
        cnt = 0; // 重置节点计数器
    }
};

trie a;

void solve() {
    a.clear();
    int n, p;
    cin >> n >> p;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        a.insert(s);
    }
    for (int i = 0; i < p; i++) {
        cin >> s;
        cout << a.search_prefix_s(s) << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}