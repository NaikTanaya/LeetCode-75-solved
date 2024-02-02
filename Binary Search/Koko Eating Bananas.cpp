class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Initialize search space
        long long int left = 1;
        long long int right = *std::max_element(piles.begin(), piles.end());
        long long int ans = right;

        // Binary search
        while (left <= right) {
            // Calculate the middle value
            long long int mid = left + (right - left) / 2;
            long long int hours = 0;

            // Calculate total hours required to eat all bananas at the current speed
            for (auto bananas : piles) {
                hours += (bananas + mid - 1) / mid;
            }

            // Update answer if the current speed allows all bananas to be eaten within h hours
            if (hours <= h) {
                ans = min(ans, mid);
                // Explore lower eating speeds
                right = mid - 1;
            } else {
                // Explore higher eating speeds
                left = mid + 1;
            }
        }
        return ans;
    }
};

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4

// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23
