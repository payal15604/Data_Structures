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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp -> next;
        }
        temp = head;
        ListNode* prev = temp;
        if(len < k){
            for(int i = 0; i < len; i++){
                prev = temp;
                head = temp;
                temp = temp -> next;
                prev -> next = NULL;
                ans.push_back(head);
            }
            for(int i = 0; i < k - len; i++){
                ans.push_back(NULL);
            }
            return ans;
        }
    
        int elements = len / k;
        int remain = len % k;
        while(remain > 0){
            head = temp;
            for(int i = 0; i < elements + 1; i++){
                prev = temp;
                temp = temp -> next;
            }
            prev -> next = NULL;
            ans.push_back(head);
            remain--;
        }
        while(temp != NULL){
            prev = temp;
            head = temp;
            for(int i = 0; i < elements; i++){
                prev = temp;
                temp = temp -> next;
            }
            prev -> next = NULL;
            ans.push_back(head);
        }
        return ans;
        
    }
};