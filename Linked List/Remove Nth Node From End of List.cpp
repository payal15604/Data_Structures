class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int length = 0;

        // Calculate the length of the list
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // If n equals length, remove the head
        if (n == length) {
            ListNode* new_head = head->next;
            delete head;
            return new_head;
        }

        // Find the node just before the one we need to remove
        temp = head;
        for (int i = 1; i < length - n; i++) {
            temp = temp->next;
        }

        // Remove the nth node from the end
        ListNode* node_to_delete = temp->next;
        temp->next = temp->next->next;
        delete node_to_delete;

        return head;
    }
};
