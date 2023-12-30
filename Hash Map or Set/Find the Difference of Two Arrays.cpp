class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> setNums1(nums1.begin(), nums1.end());
        unordered_set<int> setNums2(nums2.begin(), nums2.end());
        unordered_set<int> seen;

        vector<int> distinctInNums1, distinctInNums2;

        for (int element : nums1) {
            if (setNums2.find(element) == setNums2.end() &&
                seen.find(element) == seen.end()) {
                distinctInNums1.push_back(element);
                seen.insert(element);
            }
        }

        for (int element : nums2) {
            if (setNums1.find(element) == setNums1.end() &&
                seen.find(element) == seen.end()) {
                distinctInNums2.push_back(element);
                seen.insert(element);
            }
        }

        return {distinctInNums1, distinctInNums2};
    }
};

// Example 1:

// Input: nums1 = [1,2,3], nums2 = [2,4,6]
// Output: [[1,3],[4,6]]
// Explanation:
// For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
// For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

// Example 2:

// Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
// Output: [[3],[]]
// Explanation:
// For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
// Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
