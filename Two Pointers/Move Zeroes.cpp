class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        int length=nums.size();
        for(int i=0;i<length;i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[j],nums[i]);
                j++;
            }
        }
    }
};


// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

// Example 2:

// Input: nums = [0]
// Output: [0]
