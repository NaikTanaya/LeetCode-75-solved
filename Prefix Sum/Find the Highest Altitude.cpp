class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int length = gain.size();
        vector<int> prefix(length + 1, 0);
        for (int i = 1; i <=length; i++) {
            prefix[i] = prefix[i - 1] + gain[i-1];
        }
        // sort(prefix.begin(), prefix.end());
        int highest_value = *max_element(prefix.begin(), prefix.end());

        return highest_value;
    }
};

// Example 1:

// Input: gain = [-5,1,5,0,-7]
// Output: 1
// Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.

// Example 2:

// Input: gain = [-4,-3,-2,-1,4,3,2]
// Output: 0
// Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.
