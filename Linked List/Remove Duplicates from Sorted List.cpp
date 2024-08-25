class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* temp = head;

        while (temp != nullptr && temp->next != nullptr) {
            if (temp->val == temp->next->val) {
                ListNode* store = temp->next->next;
                delete temp->next;
                temp->next = store;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};
