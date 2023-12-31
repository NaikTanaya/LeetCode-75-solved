class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> intFrequency;

        for (int num : arr) {
            intFrequency[num]++;
        }
        unordered_set<int> frequenciesSeen;
        for (const auto& entry : intFrequency) {
            if (frequenciesSeen.count(entry.second) > 0) {
                // Duplicate frequency found
                return false;
            } else {
                frequenciesSeen.insert(entry.second);
            }
        }
        return true;
    }
};

// Example 1:

// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

// Example 2:

// Input: arr = [1,2]
// Output: false

// Example 3:

// Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
// Output: true
