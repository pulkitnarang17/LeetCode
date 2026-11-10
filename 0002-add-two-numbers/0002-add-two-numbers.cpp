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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify the creation of the result list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        
        // Loop runs if there are nodes in l1, l2, or a leftover carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            
            // If l1 is not exhausted, add its value and move to next
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            // If l2 is not exhausted, add its value and move to next
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Update carry for the next digits (e.g., 15 / 10 = 1)
            carry = sum / 10;
            
            // Create a new node with the unit digit (e.g., 15 % 10 = 5)
            curr->next = new ListNode(sum % 10);
            
            // Move the current pointer forward
            curr = curr->next;
        }
        
        // Store the actual head of the result list
        ListNode* head = dummy->next;
        
        // Free the dummy node to prevent memory leaks (good C++ practice)
        delete dummy; 
        
        return head;
    }
};