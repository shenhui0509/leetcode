#include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    list_node* next;
    list_node(int x) : val(x), next(nullptr){}
};

list_node* create(const vector<int>& num){
    list_node* prev = new list_node(-1);
    list_node* cur = prev;
    for(auto i : num){
        list_node* nd = new list_node(i);
        cur->next = nd;
        cur = nd;
    }
    list_node* head = prev->next;
    delete(prev);
    return head;
}

list_node* destroy(list_node* head){
    list_node* p = head, *cur = head;

    while(p){
        p = cur->next;
        delete(cur);
        cur = p;
    }
}
void print_list(list_node* head){
    list_node* p = head;
    while(p){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}
list_node* merge_two_list(list_node* l1, list_node* l2)
{
    list_node* head = nullptr, **t = &head;
    while(l1 != nullptr && l2 != nullptr){
        if(l1->val < l2->val){
            *t = l1;
            l1 = l1->next;
        } else {
            *t = l2;
            l2 = l2->next;
        }
        t = &((*t)->next);
    }
    *t = (l1 != nullptr ? l1 : l2);
    return head;
}
int main(int argc, char const *argv[])
{
    list_node* l1 = create(vector<int>{2,4,6,8,10});
    list_node* l2 = create(vector<int>{1,2,5,7,9});
    list_node* l3 = merge_two_list(l1,l2);
    print_list(l3);

    return 0;
}