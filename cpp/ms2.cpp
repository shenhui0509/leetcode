#include <bits/stdc++.h>
using namespace std;
const int nmax = 1000005;

struct Trie
{
    Trie* child[2];
    int id;
    Trie(){
        child[0] = nullptr;
        child[1] = nullptr;
        id = 0;
    }
};

Trie* allow;
Trie* deny;

Trie* create_node(){
    Trie* node = new Trie;
    return node;
}

void trie_insert(Trie* root, int ip, int mask, int id){
    Trie* node = root;
    if(root->id) return;
    int shift = 31;
    while(shift >= 0 && mask > 0){
        int n = (ip >> shift) & 0x01;
        if(node->child[n] == nullptr){
            node->child[n] = create_node();
        }
        if(node->id && mask != 0){
            return;
        } // shorter rules came before longer rules
        node = node->child[n];
        shift--;
        mask--;
    }
    node->id = id; // for the same rules, the previous is remained
}

int trie_search(Trie* root, int ip){
    Trie* node = root;
    int id = root->id == 0 ? INT_MAX : root->id;
    int shift = 31;
    while(shift >= 0){
        int i = (ip >> shift) & 0x01;
        if(node->child[i] == nullptr){
            break;
        }
        node = node->child[i];
        if(node->id) id = min(id,node->id);
        shift--;
    }
    return id;     
}

void trie_destroy(Trie* root){
    if(!root)
        return;
    Trie* node = root;
    if(node->child[0]) trie_destroy(node->child[0]);
    if(node->child[1]) trie_destroy(node->child[1]);
    delete root;
    root = nullptr;
    return;
}

int ip_string_to_int(char* c){
    int a[4];
    sscanf(c,"%d.%d.%d.%d", &a[0],&a[1],&a[2],&a[3]);
    int result = 0x00;
    for(int i = 0; i <= 3; i++){
        result |= (a[i] << (8*(3-i)));
    }
    return result;
}



int main()
{
    // freopen("in","r",stdin);
    int n,m;
    scanf("%d %d\n",&n,&m);
    char buf[123];
    allow = create_node();
    deny = create_node();
    for(int i = 1; i <= n; i++){
        gets(buf);
        int len = strlen(buf);
        if(buf[0] == 'a'){
            int addr = ip_string_to_int(buf+6);
            int k = len-1;
            for(; k>0&&buf[k]!='/';k--);
            //printf("%d\n", k);
            int mask;
            if(k == 0) mask = 32;
            else{
                mask = atoi(buf+k+1);
            }
            trie_insert(allow, addr, mask, i);
        } else if(buf[0] == 'd'){
            int addr = ip_string_to_int(buf+5);
            int k = len - 1;
            for(; k > 0 && buf[k] != '/'; k--);
            int mask;
            if(k == 0) mask = 32;
            else{
                mask = atoi(buf+k+1);
            }
            trie_insert(deny, addr, mask, i);
        }
    }
    for(int i = 1; i <= m; i++){
        gets(buf);
        int addr = ip_string_to_int(buf);
        int ac = trie_search(allow, addr);
        int de = trie_search(deny, addr);
        ac < de ? puts("YES"):puts("NO");
    }

    trie_destroy(allow);
    trie_destroy(deny);
    // fclose(stdin);
    return 0;
}