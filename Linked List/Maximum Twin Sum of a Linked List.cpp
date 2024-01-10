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
    int pairSum(ListNode* head) {
        stack<int> st; // new stack to store the value of every listnode of the
                       // linklist

        ListNode* temp = head;

        while (temp != NULL) {
            st.push(temp->val); // storing the value of every listnode of the
                                // linklist int stack
            temp = temp->next;
        }
        int sum = 0;
        int maxsum = INT_MIN;
        for (int i = 0; i < st.size(); i++) {
            sum = st.top() + head->val; // calculating the sum at every twin
                                        // node
            maxsum =
                max(maxsum, sum); // keep track the maximum sum and return it
            st.pop();
            head = head->next;
        }
        return maxsum;
    }
}
;

// Example 1:

// Input: head = [5,4,2,1]
// Output: 6
// Explanation:
// Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
// There are no other nodes with twins in the linked list.
// Thus, the maximum twin sum of the linked list is 6. 

// Example 2:

// Input: head = [4,2,2,3]
// Output: 7
// Explanation:
// The nodes with twins present in this linked list are:
// - Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
// - Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
// Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 

// Example 3:

// Input: head = [1,100000]
// Output: 100001
// Explanation:
// There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
