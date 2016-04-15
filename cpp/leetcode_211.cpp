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

    bool search(string word) {
        return search(word, root);
    }


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
    bool search(string word, TrieNode* r){
        TrieNode* node = r;
        size_t i = 0;
        int id;
        for(; i < word.size(); i++){
            if(word[i] == '.'){
                for(int j = 0; j < 26; j++){
                    if(node->next[j] == NULL) continue;
                    else {
                        if(search(word.substr(i+1,string::npos), node->next[j])){
                            return true;
                        }
                    }
                }
                return false;
            } else {
                id = word[i] - 'a';
                if (node->next[id] == NULL) {
                    return false;
                }
                node = node->next[id];
            }

        }
        return node->is_word;
    }
    void destroy(TrieNode* r){
        if(!r) return;
        for(int i = 0; i < 26; i++){
            if(r->next[i]) destroy(r->next[i]);
        }
        delete r;
        r = NULL;
    }
};

int main(int argc, char const *argv[])
{
    Trie trie;
    trie.insert("a");
    // trie.insert("dad");
    // trie.insert("mad");
    cout << trie.search(".") << " " << trie.search(".a") /*<< " " << trie.search("a.")*/ << endl;
    return 0;
}