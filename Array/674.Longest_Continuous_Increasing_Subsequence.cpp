// Data:        2020.4.8
// Topic:       Array + GA
// Todo:        Time and space complexity

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = 1;
        int maxLen = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) ++n;
            else n = 1;
            maxLen = max(maxLen, n);
        }
        return maxLen;
    }
};
