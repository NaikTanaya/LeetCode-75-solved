class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> asteroidStk;

        for (int i = 0; i < asteroids.size(); i++) {
            int ast = asteroids[i];
            while (!asteroidStk.empty() && ast < 0 && asteroidStk.top() > 0) {
                int top = asteroidStk.top();
                asteroidStk.pop();

                if (abs(top) == abs(ast)) {
                    ast = 0;
                    break;
                } else if (abs(top) > abs(ast)) {
                    asteroidStk.push(top);
                    ast = 0;
                    break;
                }
            }
            if (ast != 0)
                asteroidStk.push(ast);
        }
        vector<int> result(asteroidStk.size());
        for (int i = result.size() - 1; i >= 0; --i) {
            result[i] = asteroidStk.top();
            asteroidStk.pop();
        }

        return result;
    }
};

// Example 1:

// Input: asteroids = [5,10,-5]
// Output: [5,10]
// Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

// Example 2:

// Input: asteroids = [8,-8]
// Output: []
// Explanation: The 8 and -8 collide exploding each other.

// Example 3:

// Input: asteroids = [10,2,-5]
// Output: [10]
// Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
