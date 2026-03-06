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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        int n = 1; // size of linked list
        ListNode* last = head;
        while (last->next != nullptr) {
            n++;
            last = last->next;
        }
        k = k % n ;
        if (k == 0) { return head; }
        int c = n - k;
        ListNode* temp = head;
        int count = 1;
        while (temp) {
            if (count == c) {
                break;
            }
            count++;
            temp = temp->next;
        }
        ListNode* res = temp->next;
        last->next = head;
        temp->next = nullptr;
        return res;
    }
};
