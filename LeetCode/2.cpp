/* ------------------------------*/
/* Created by LinX on 2021/04/15.*/
/* ------------------------------*/
/*
 name: 两数之和(链表计算)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int len1 = 1;
        int len2 = 1;
        while(p1->next!=nullptr) {
            len1 += 1;
            p1 = p1->next;
        }
        while(p2->next!=nullptr) {
            len2 += 1;
            p2 = p2->next;
        }
        if(len1>=len2) {
            for(int i=1; i<=len1-len2;i++) {
                p2->next = new ListNode(0);
                p2 = p2->next;
            }
        }
        else {
            for(int i=1; i<=len2-len1;i++) {
                p1->next = new ListNode(0);
                p1 = p1->next;
            }
        }
        p1 = l1;
        p2 = l2;
        ListNode* ans = new ListNode();
        ListNode* pos = ans;
        int count = 0;
        int sum;
        while(p1!=nullptr) {
            sum = p1->val + p2->val + count;
            count = sum/10;
            pos->next = new ListNode(sum%10);
            pos = pos->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        if(count==1){
            pos->next = new ListNode(1);
            pos = pos->next;
        }
        return ans->next;
    }
};