// Data:        2020.4.8
// Topic:       Array + 
// Todo:        Time and space complexity
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int maxSize = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int size = (right - left) * min(height[right], height[left]);
            maxSize = max(maxSize, size);
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxSize;
    }
};
