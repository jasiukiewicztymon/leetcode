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
    vector<ListNode*> l;
    ListNode* removeNthFromEnd(ListNode* head, int t) {
        ListNode* n = head;
        while (n != nullptr) {
            l.push_back(n);
            n = n->next;
        }

        if (t == 1) {
            if (l.size() == 1)
                l[0] = nullptr;
            else
                l[l.size() - 2]->next = nullptr;
            return l[0]; 
        }
        else if (t == l.size()) {
            return l[1];
        }
        else {
            l[l.size() - t - 1]->next = l[l.size() - t]->next;
            return l[0];
        }
    }
};
