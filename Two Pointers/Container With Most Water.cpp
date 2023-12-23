class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size();
        int left = 0;
        int right = length - 1;
        int area = 0;

        while (left < right) {
            area = max(area, min(height[left], height[right]) * (right - left));

            if (height[left] < height[right]) {
                left += 1;
            } else {
                right -= 1;
            }
        }
        return area;
    }
};
