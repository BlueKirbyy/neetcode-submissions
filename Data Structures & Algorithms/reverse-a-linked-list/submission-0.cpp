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
    ListNode* reverseList(ListNode* head) {
        //start by creating 3 variables to store prev, next, and current.
        //while current listnode does not hit nullptr
        //reverse the list
        //save where youre going next with next = current->next
        //then reverse the arrow tih current->next = previous
        //previous becomes the current
        //current becomes the next

        //return the previous because it is pointing to the new first node

        ListNode* previous = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while(current != nullptr){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }
};
