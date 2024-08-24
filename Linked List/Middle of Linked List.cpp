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
    ListNode* middleNode(ListNode* head) {
        int len = length(head);
        int mid = len/2;
        ListNode* curr = head;

        while(mid != 0)
        {
            curr = curr-> next;
            mid--;
        }

        return curr;
        
    }
private:
    int length(ListNode* head)
    {
        int count = 0;
        while(head->next != nullptr)
        {
            head = head->next;
            count++;
        }

        return count+1;
    }
};