#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        is_word = false;
        memset(next, 0, sizeof(next));
    }
    bool is_word;
    TrieNode* next[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie(){
        destroy(root);
    }
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        size_t i = 0;
        int id;
        for(;i < word.size(); i++){
            id = word[i] - 'a';
            if(node->next[id] == NULL){
                node->next[id] = new TrieNode();
            }
            node = node->next[id];
        }
        node->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        size_t i = 0;
        int id;
        for(; i < word.size(); i++){
            id = word[i] - 'a';
            if(node->next[id] == NULL){
                return false;
            }
            node = node->next[id];
        }
        return node->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        size_t i = 0;
        int id;
        int cnt = 0;
        for(; i < prefix.size(); i++){
            id = prefix[i] - 'a';
            if(node->next[id] == NULL){
                break;
            }
            node = node->next[id];
            cnt++;
        }
        return cnt == prefix.size();
    }

private:
    TrieNode* root;
    void destroy(TrieNode* r){
        if(!r) return;
        for(int i = 0; i < 26; i++){
            if(r->next[i]) destroy(r->next[i]);
        }
        delete r;
        r = NULL;
    }
};
void dfs(vector<vector<char>>& board, int i, int j, int m, int n, unordered_set<string>& result, 
        Trie& trie, string prefix)
{
    if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '\0'){
        return;
    }
    size_t cur = prefix.size();
    cout << i << " " << j << " " << prefix << " " << board[i][j] << endl;
    char t = board[i][j];
    board[i][j] = '\0';
    prefix.append(1, t);
    if(trie.search(prefix)){
        result.insert(prefix);
    }
    if(trie.startsWith(prefix)){
        dfs(board, i+1,j,m,n,result,trie,prefix);
        dfs(board, i-1,j,m,n,result,trie,prefix);
        dfs(board, i, j+1, m, n, result, trie, prefix);
        dfs(board, i, j-1, m, n, result, trie, prefix);
    }
    board[i][j] = t;
    prefix.resize(cur);
    return;
}
vector<string> find_words(vector<vector<char>>& board, vector<string>&words)
{
    Trie trie;
    for(auto word : words){
        trie.insert(word);
    }
    unordered_set<string> result;
    int i,j,m=board.size(),n=board[0].size();
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            dfs(board,i,j,m,n,result,trie,string(""));
        }
    }
    vector<string> res(result.begin(), result.end());
    return res;
}



int main()
{
    vector<vector<char>> board = {{'a','b'},
                                  {'a','a'}};/*{{'o','a','a','d'},
                                  {'s','f','c','s'},
                                  {'s','c','e','g'}};*/
    vector<string> words = {"aaa","aaab"};/*{"abc","cce","dfff","assc","asfc"};*/
    vector<string> result = find_words(board,words);
    for(auto word : result){
        cout << word << endl;
    }
    return 0;
}