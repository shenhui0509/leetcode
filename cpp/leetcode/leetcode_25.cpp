#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* reverseKGroup(ListNode* head, int k){
    if(head == NULL || k == 1) return head;
    int num = 0;
    ListNode* pre_header = new ListNode(-1);
    pre_header->next = head;
    ListNode *cur = pre_header, *next, *pre = pre_header;
    while(cur = cur->next){
        num++;
    }
    while(num >= k){
        cur = pre->next;
        next = cur->next;
        for(int i = 1; i < k; i++){
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
            next = cur->next;
        }
        pre = cur;
        num-=k;
    }
    return pre_header->next;
}