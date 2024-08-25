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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while(head != NULL)
        {
            v.emplace_back(head->val);
            head = head->next;
        }

        int l = 0, r = v.size() - 1;
        while(l<r and v[l]==v[r])
        {
            l++;
            r--;
        }

        return l>=r;
    }
};