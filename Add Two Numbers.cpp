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
        ListNode ret(0); ListNode* p = &ret;
        int r = 0;
        while (l1 || l2) {            
            int sum = 0;
            if (r) {
                sum = r;
                r = 0;
            }
            if (l1)
                sum += l1->val;
            if (l2)
                sum += l2->val;
            
            p->next = new ListNode(sum % 10);
            p = p->next;
            
            if (sum > 9)
                r = sum / 10;
            
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if(r)
          p->next = new ListNode(r);
        return ret.next;
    }
};
