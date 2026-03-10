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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head); // protect from if left is 1
        if (head == nullptr || left == right)
            return dummy->next;
        ListNode* before; // before node, reversal is start
        ListNode* after;  // last node of reversed LL
        // place before after there respective position
        before = dummy;
        for (int i = 1; i < left; i++) {
            before = before->next;
        }
        after = before->next;
        //Reversal Start
        ListNode* curr = after;
        ListNode* prev = nullptr;
        ListNode* next;
        int times = right-left+1;
        while(times--){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        //Joining destructed nodes
        before->next = prev;
        after->next = curr;
        //return original head
        return dummy->next;
    }
};