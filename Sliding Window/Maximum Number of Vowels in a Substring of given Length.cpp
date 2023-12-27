class Solution {
public:
    int maxVowels(string s, int k) {
        int length = s.size();
        int count = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                count++;
            }
        }
        int max_count = count;

        for (int i = k; i < length; i++) {

            // Remove the vowel that is no longer part of the window
            if (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' ||
                s[i - k] == 'o' || s[i - k] == 'u') {
                count--;
            }

            // Add the vowel that is now part of the window
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                count++;
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }
};


// Example 1:

// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.

// Example 2:

// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.

// Example 3:

// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.
