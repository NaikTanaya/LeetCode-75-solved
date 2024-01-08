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

// struct ListNode
// {
//     int value;
//     ListNode *next;

//     ListNode(int x) : val(x), next(nullptr) {}
// };


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            // No middle node to delete if the list is empty or has only one node.
            return NULL;
        }

        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // Use two pointers to find the middle node.
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

                // Skip the middle node by adjusting pointers.
        if (prev != NULL) {
            prev->next = slow->next;
            delete slow;  // Free memory of the middle node.
        }

        return head;
    }
};

// Example 1:

// Input: head = [1,3,4,7,1,2,6]
// Output: [1,3,4,1,2,6]
// Explanation:
// The above figure represents the given linked list. The indices of the nodes are written below.
// Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
// We return the new list after removing this node. 

// Example 2:

// Input: head = [1,2,3,4]
// Output: [1,2,4]
// Explanation:
// The above figure represents the given linked list.
// For n = 4, node 2 with value 3 is the middle node, which is marked in red.

// Example 3:

// Input: head = [2,1]
// Output: [2]
// Explanation:
// The above figure represents the given linked list.
// For n = 2, node 1 with value 1 is the middle node, which is marked in red.
// Node 0 with value 2 is the only node remaining after removing node 1.
