class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> a;

        // Create a vector of pairs and sort in descending order based on nums2 values
        for(int i = 0; i < n; i++) {
            a.push_back({nums1[i], nums2[i]});
        }
        sort(a.rbegin(), a.rend(), [&](pair<int, int> x, pair<int, int> y){
            return x.second < y.second;
        });

        long long sm = 0;
        priority_queue<int, vector<int>, greater<int>> q;

        // Calculate the initial score with the first k elements
        for(int i = 0; i < k; i++) {
            sm += a[i].first;
            q.push(a[i].first);
        }
        
        long long res = sm * a[k - 1].second;

        // Iterate from index k to n-1 and update the score
        for(int i = k; i < n; i++) {
            sm -= q.top();
            q.pop();
            sm += a[i].first;
            q.push(a[i].first);
            res = max(res, sm * a[i].second);
        }

        return res;
    }
};

// Approach
// -Create a vector a of pairs, where each pair contains a value from nums1 and the corresponding value from nums2.
// -Sort the vector a in descending order based on the values from nums2.
// -Initialize a variable sm to keep track of the sum of selected elements from nums1. Also, use a priority queue q to keep track of the minimum elements selected so far.
// -Iterate through the first k elements of the sorted vector a, updating sm and pushing the values into the priority queue q.
// -Calculate the initial score res as the product of sm and the minimum value from the first k elements of nums2.
// -Iterate from index k to n-1 in the sorted vector a. For each iteration, update sm by subtracting the top element from the priority queue, adding the current element from nums1, and pushing the current element into the priority queue.
// -Update the maximum score res as the maximum of the current score (sm * a[i].second) and the previous maximum.
// -Return the final maximum score.

// Complexity
// Time complexity: O(n log n) - Sorting the vector takes O(n log n) time, and the subsequent iterations take O(n) time.
// Space complexity: O(n) - Additional space is used for the vector a and the priority queue.

// Example 1:

// Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
// Output: 12
// Explanation: 
// The four possible subsequence scores are:
// - We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
// - We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6. 
// - We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12. 
// - We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
// Therefore, we return the max score, which is 12.

// Example 2:

// Input: nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
// Output: 30
// Explanation: 
// Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the maximum possible score.
