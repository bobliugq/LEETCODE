// Data:        2020.4.8
// Topic:       Array + 
// Todo:        Time and space complexity
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int n = height.size();
        int size = 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
           left[i] = max(height[i], left[i - 1]);
           right[n - i - 1] = max(height[n - i - 1], right[n - i]); 
        }
        for (int i = 0; i < n; ++i) {
            size += min(left[i], right[i]) - height[i];
        }
        return size;
    }
};
