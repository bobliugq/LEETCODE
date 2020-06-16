// Topic : GA algortihm + two pointers
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxSize = 0;
        while (left < right) {
            int curSize = min(height[left], height[right]) * (right - left);
            maxSize = max(maxSize, curSize);
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxSize;
    }
};
