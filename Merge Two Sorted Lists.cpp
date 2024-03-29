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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode();

        if (list1 == nullptr) 
            return list2;
        else if (list2 == nullptr) 
            return list1;

        if (list1->val < list2->val) {
            res->val = list1->val;
            res->next = mergeTwoLists(list1->next, list2);
            return res;
        }
        res->val = list2->val;
        res->next = mergeTwoLists(list2->next, list1);
        return res;
    }
};
