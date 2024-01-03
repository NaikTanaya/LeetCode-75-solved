class Solution {
public:
    string removeStars(string s) {

        string result; // Use a string to directly store the result

        for (char c : s) {
            if (c != '*') {
                result.push_back(c); // Append non-star characters directly
            } else if (!result.empty()) {
                result.pop_back(); // Remove the last character if it's a star
            }
        }

        return result;
    }
};


// Example 1:

// Input: s = "leet**cod*e"
// Output: "lecoe"
// Explanation: Performing the removals from left to right:
// - The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
// - The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
// - The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
// There are no more stars, so we return "lecoe".

// Example 2:

// Input: s = "erase*****"
// Output: ""
// Explanation: The entire string is removed, so we return an empty string.
