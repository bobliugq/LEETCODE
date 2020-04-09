// Data:        2020.4.8
// Topic:       Array + GA
// Todo:        Time and space complexity
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int maxArr = 1;
        int n = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                ++n;
            } else {
                n = 1;
            }
            maxArr = max(maxArr, n);
        }
        return maxArr;
    }
};
