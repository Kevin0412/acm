#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    int children[26]={0};
    int fail=0;
    vector<int> pattern_indices;
    int count=0;
    TrieNode()=default;
};

class AhoCorasick{
private:
    vector<TrieNode>trie;
    int node_count=0;

    int new_node(){
        trie.emplace_back();
        return node_count++;
    }

public:
    AhoCorasick(){
        trie.reserve(200005);
        new_node();
    }

    void insert(const string& pattern,int pattern_idx){
        int current_node=0;
        for(char ch:pattern){
           int c_idx=ch-'a';
           if(trie[current_node].children[c_idx]==0){
            trie[current_node].children[c_idx]=new_node();
           }
           current_node=trie[current_node].children[c_idx];
        }
        trie[current_node].pattern_indices.push_back(pattern_idx);
    }

    void build_failure_links(){
        queue<int> q;
        for(int i=0;i<26;++i){
            if(trie[0].children[i]!=0){
                q.push(trie[0].children[i]);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=0;i<26;++i){
                int v=trie[u].children[i];
                if(v==0){
                    trie[u].children[i]=trie[trie[u].fail].children[i];
                    continue;
                }
                int f=trie[u].fail;
                trie[v].fail=trie[f].children[i];
                q.push(v);
            }
        }
    }

    void query(const string&text){
        int current_node=0;
        for(char ch:text){
            int c_idx=ch-'a';
            current_node=trie[current_node].children[c_idx];
            trie[current_node].count++;
        }
    }
    vector<int> get_final_pattern_counts(int num_patterns){
        vector<int> in_degree(node_count,0);
        for(int i=1;i<node_count;++i){
            in_degree[trie[i].fail]++;
        }
        queue<int> q;
        for(int i=1;i<node_count;++i){
            if(in_degree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty(){
            int u=q.front();
            q.pop();
            trie[trie[u].fail].count+=
        })
    }
}

int main(){


}