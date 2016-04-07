#include <iostream>
#include <cstring>
using namespace std;

struct trie_node{
    int count;
    trie_node* next[26];
    bool is_word;
};

trie_node* create_trie_node()
{
    trie_node* node = new trie_node;
    node->count = 0;
    memset(node->next, 0, sizeof(node->next));
    node->is_word = false;
    return node;
}

void trie_insert(trie_node* root, const char* word)
{
    trie_node *node = root;
    const char *p = word;
    int id;
    while(*p){
        id = *p - 'a';
        if(node->next[id] == NULL)
        {
            node->next[id] = create_trie_node();
        }
        node = node->next[id];
        ++p;
        ++node->count;
    }
    node->is_word = true;
}

int trie_search(trie_node* root, const char* word)
{
    trie_node *node = root;
    const char *p = word;
    int id;
    while(*p){
        id = *p - 'a';
        node = node->next[id];
        ++p;
        if(node == NULL){
            return 0;
        }
    }
    return node->count;
}

void trie_destroy(trie_node* root)
{
    if(!root)
        return;
    trie_node* node = root;
    for(int i = 0; i < 26; i++){
        if(node->next[i] != NULL){
            trie_destroy(node->next[i]);
        }
    }
    delete root;
    root = NULL;
    return;
}
int main()
{
    trie_node* root = create_trie_node();
    bool flag = false;
    string str;
    int nums;
    cin >> nums;
    while(nums > 0){
        cin >> str;
        trie_insert(root, str.c_str());
        nums--;
    }
    cin >> nums;
    while(nums > 0){
        cin >> str;
        cout << trie_search(root, str.c_str()) << endl;
        nums--;
    }
    return 0;
}
