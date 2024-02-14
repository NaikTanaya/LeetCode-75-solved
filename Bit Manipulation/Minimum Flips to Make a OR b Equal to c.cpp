class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = 0;

        for(int i = 0; i < 32; i++) {
            bool ai = (a & (1 << i)); // taking the ith bit in a
            bool bi = (b & (1 << i)); // taking the ith bit in b
            bool ci = (c & (1 << i)); // taking the ith bit in c

            if(ci) {
                if(!ai && !bi) flip++;
            } else {
                if(ai && bi) flip += 2;
                else if(ai || bi) flip++;
            }
        }
        return flip;
    }
};

// Example 1:

// Input: a = 2, b = 6, c = 5
// Output: 3
// Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)

// Example 2:

// Input: a = 4, b = 2, c = 7
// Output: 1

// Example 3:

// Input: a = 1, b = 2, c = 3
// Output: 0
