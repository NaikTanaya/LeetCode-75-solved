
class Solution {
public:
    int guessNumber(int n) {

        int start = 1;
        int end = n;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (guess(mid) == -1) {
                end = mid;
            } else if (guess(mid) == 1) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return 0;
    }
};

// Example 1:

// Input: n = 10, pick = 6
// Output: 6
// Example 2:

// Input: n = 1, pick = 1
// Output: 1
// Example 3:

// Input: n = 2, pick = 1
// Output: 1
