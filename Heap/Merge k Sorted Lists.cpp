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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //what is the algorithm i'll use
        // how about i use the concept of priority queues and min heap
        //i can traverse through the vector and put all the head nodes in the priority queue 
        // ofc when they are not null
        // min heap - minimum at root 
        // extract top element and put it at the result list
        //if it has any non null next node, add it to min heap

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> minHeap;
        //by default the pq is max heap, so we used greater to convert it to min heap

        for(auto list : lists)
        {
            if(list != nullptr)
            {
                minHeap.push({list->val, list});
            }
            
        } 

        ListNode* dummy = new ListNode(0); //0 is the value
        ListNode* current = dummy;

        while(!minHeap.empty())
        {
            auto [val, node] = minHeap.top();
            minHeap.pop();
            //current->val= val;
            current ->next = node;
            current = current->next; 

            if(node->next != nullptr)
            {
                minHeap.push({node->next->val, node->next});
            }

            
        }


        return dummy->next;
        
    }
};