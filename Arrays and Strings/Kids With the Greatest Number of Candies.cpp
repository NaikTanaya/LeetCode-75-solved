class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int x = 0;
        vector<bool> y;
        bool m;
        for (int i = 0; i < candies.size(); i++) {
            x = candies[i] + extraCandies;
            m = true;
            for (int j = 0; j < candies.size(); j++) {
                if (x < candies[j]) {
                    m = false;
                    break;
                }
            }
            y.push_back(m);
        }
        return y;
    }
};
