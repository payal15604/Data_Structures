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
    void reorderList(ListNode* head) {
        //how does the algorithm look like
        //first we need to find the middle of the list through fast and slow pointers
        //reverse the second half of the list 
        //traverse while second doesnt reach null
        if (!head || !head->next) return;  

        ListNode* fast = head->next; 
        ListNode* slow = head;

        while(fast != nullptr and fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;

        while(second != nullptr)
        {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        second = prev;
        ListNode* first = head;

        while(second != nullptr)
        {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;

        }

    }
};