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
    ListNode* merge(ListNode* a, ListNode* b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;

        if (a->val < b->val) {
            a->next = merge(a->next,b);
            return a;
        }
        else {
            b->next = merge(b->next,a);
            return b;
        }

        return nullptr;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;

        for(int i = 1; i < lists.size(); i++){
            lists[0] = merge(lists[0], lists[i]);
        }        

        return lists[0];
    }
};
