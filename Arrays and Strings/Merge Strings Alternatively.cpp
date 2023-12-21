class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int len1 = word1.length();
        int len2 = word2.length();
        int maxlen = max(len1, len2);

        for (int i = 0; i < maxlen; i++) {
            if (i < len1) {
                res += word1[i];
            }
            if (i < len2) {
                res += word2[i];
            }
        }

        return res;
    }
};


// Example 1:

// Input: word1 = "abc", word2 = "pqr"
// Output: "apbqcr"
// Explanation: The merged string will be merged as so:
// word1:  a   b   c
// word2:    p   q   r
// merged: a p b q c r

// Example 2:

// Input: word1 = "ab", word2 = "pqrs"
// Output: "apbqrs"
// Explanation: Notice that as word2 is longer, "rs" is appended to the end.
// word1:  a   b 
// word2:    p   q   r   s
// merged: a p b q   r   s

// Example 3:

// Input: word1 = "abcd", word2 = "pq"
// Output: "apbqcd"
// Explanation: Notice that as word1 is longer, "cd" is appended to the end.
// word1:  a   b   c   d
// word2:    p   q 
// merged: a p b q c   d
