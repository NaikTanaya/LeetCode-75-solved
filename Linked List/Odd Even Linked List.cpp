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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        ListNode* oddStart = NULL; // ODD INDEX
        ListNode* oddEnd = NULL;
        ListNode* evenStart = NULL; // EVEN INDEX
        ListNode* evenEnd = NULL;
        int i = 1;

        if (head == NULL || head->next == NULL) {
            // No middle node to delete if the list is empty or has only one
            // node.
            return head;
        }

        while (temp != NULL) {

            if (i % 2 == 0) {
                // even
                if (evenStart == NULL) {
                    evenStart = temp;

                } else {
                    evenEnd->next = temp;
                }
                evenEnd = temp;
            } else {
                // odd
                if (oddStart == NULL) {
                    oddStart = temp;
                } else {
                    oddEnd->next = temp;
                }
                oddEnd = temp;
            }
            temp = temp->next;
            i++;
        }

        // now join the odd end with even start
        oddEnd->next = evenStart;
        // even end is new end so put NULL
        evenEnd->next = NULL;

        head = oddStart; // new head
        return oddStart;
    }
};


// Example 1:

// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]

// Example 2:

// Input: head = [2,1,3,5,6,4,7]
// Output: [2,3,6,7,1,5,4]
