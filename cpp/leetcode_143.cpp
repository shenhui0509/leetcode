#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

ListNode* create(const vector<int>& num){
    ListNode* prev = new ListNode(-1);
    ListNode* cur = prev;
    for(auto i : num){
        ListNode* nd = new ListNode(i);
        cur->next = nd;
        cur = nd;
    }
    ListNode* head = prev->next;
    delete(prev);
    return head;
}

ListNode* destroy(ListNode* head){
    ListNode* p = head, *cur = head;

    while(p){
        p = cur->next;
        delete(cur);
        cur = p;
    }
}

void print_list(ListNode* head){
    ListNode* p = head;
    while(p){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

ListNode* reverse(ListNode* head)
{
    ListNode* pre = NULL;
    ListNode* cur = head;
    ListNode* nxt = NULL;
    while(cur){
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

ListNode* merge(ListNode* l1, ListNode* l2)
{
    ListNode* head = nullptr, **t = &head;
    while(l1 != nullptr && l2 != nullptr){
        *t = l1;
        l1 = l1->next;
        t = &((*t)->next);
        *t = l2;
        l2 = l2->next;
        t = &((*t)->next);
    }
    *t = (l1 != nullptr ? l1 : l2);
    return head;
}

void reorderList(ListNode* head)
{
    ListNode* slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* p2 = slow->next;
    print_list(p2);
    slow->next = NULL;
    p2 = reverse(p2);
    print_list(p2);
    head = merge(head, p2);
}

int main(int argc, char const *argv[])
{
    ListNode* l1 = create(vector<int>{1,2,3,4,5,6,7,8,9,10,11});
    // ListNode* l2 = create(vector<int>{1,2,5,7,9});
    // ListNode* l3 = merge(l1,l2);
    print_list(l1);
    reorderList(l1);
    print_list(l1);

    return 0;
}