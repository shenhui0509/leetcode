#include <bits/stdc++.h>
using namespace std;

const int nmax = 100010;
int n = 0;
int heap[nmax];

inline int p(int x) {return x>>1;}
inline int l(int x) {return x<<1;}
inline int r(int x) {return (x<<1)+1;}

void heapify(int root)
{
    int left = l(root), right = r(root);
    int largest;
    if(left <= n && heap[left] > heap[root]) largest = left;
    else largest = root;
    if(right <= n && heap[right] > heap[largest]) largest = right;
    if(largest != root){
        swap(heap[root],heap[largest]);
        heapify(largest);
    }   
}

void insert(int key)
{
    ++n;
    heap[n] = key;
    int i = n;
    while(i > 1 && heap[p(i)] < heap[i]){
        swap(heap[p(i)],heap[i]);
        i = p(i);
    }
}

int get_max()
{
    int m = heap[1];
    heap[1] = heap[n];
    --n;
    heapify(1);
    return m;
}

int main(void)
{
    freopen("in","r",stdin);
    int m;
    scanf("%d", &m);
    char ch[10];
    int w;
    for(int i = 1; i <= m; i++){
        scanf("%s %d", ch, &w);
        if(ch[0] == 'A') insert(w);
        else if(ch[0] = 'T') printf("%d\n", get_max());
    }
    fclose(stdin);
    return 0;
}