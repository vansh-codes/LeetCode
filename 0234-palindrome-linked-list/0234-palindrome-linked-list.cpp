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
    bool solve(ListNode* &start, ListNode* end) {
        if (end == NULL)
            return 1;
        bool res = solve(start, end->next) && (start->val == end->val);
        if(!res) return false;
        start = start->next;
        return res;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return 1;
        ListNode* start = head;
        return solve(start, head);
    }
};
