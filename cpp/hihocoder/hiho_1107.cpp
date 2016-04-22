#include <bits/stdc++.h>
using namespace std;

const int nmax = 10010;
const int m_size = 30;

inline int id(char c){
    return c-'a';
}

struct Trie
{
    Trie *ch[m_size];
    int cnt;
    Trie(){
        cnt = 0;
        for(int i = 0; i < m_size; i++){
            ch[i] = NULL;
        }
    }
};

Trie* root;

void insert_str(char * str)
{
    Trie*p = root;
    p->cnt++;
    for(int i = 0; p&&str[i]; i++){
        int u = id(str[i]);
        if(p->ch[u]==NULL)
            p->ch[u] = new Trie;
        p = p->ch[u];
        p->cnt++;
    }
}

int find_str(char *s)
{
    Trie* p = root;
    for(int i = 0; p && s[i]; i++){
        int u = id(s[i]);
        if(p->ch[u] == NULL)    return 0;
        p=p->ch[u];
    }
    return p->cnt;
}

int ans;
void vis(Trie *nod){
    Trie* p = nod; 
    if(p->cnt <= 5 && p->cnt > 0){ans++;return;}
    for(int i = 0; i < m_size; i++){
        if(p->ch[i]) vis(p->ch[i]);
    }
}

char s[2000010];
int main(int argc, char const *argv[])
{
    freopen("in","r", stdin);
    int n,m;
    while(~scanf("%d", &n)){
        root = new Trie;
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            insert_str(s);
        }
        ans = 0;
        vis(root);
        printf("%d", ans);
    }
    fclose(stdin);
    return 0;
}