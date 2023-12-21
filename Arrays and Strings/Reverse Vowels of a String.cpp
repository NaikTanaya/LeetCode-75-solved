class Solution {
public:
    string reverseVowels(string s) {
        int x = 0;
        int y = s.size();

        while (x <= y) {
            if (isVowel(s[x]) && isVowel(s[y])) {
                char temp = s[x];
                s[x] = s[y];
                s[y] = temp;
                x++;
                y--;
            } else if (isVowel(s[x])) {
                y--;
            } else if (isVowel(s[y])) {
                x++;
            } else {
                x++;
                y--;
            }
        }
        return s;
    }

private:
    bool isVowel(char c) {
        // Convert to lowercase to handle both cases
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};


// Example 1:

// Input: s = "hello"
// Output: "holle"

// Example 2:

// Input: s = "leetcode"
// Output: "leotcede"
