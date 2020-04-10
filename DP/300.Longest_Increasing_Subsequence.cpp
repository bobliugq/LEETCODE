// Date:        2020.4.9
// Topic:       Array + DP
// Todo:        optimization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> dp(nums.size(), 0);
        int maxLIS = 1;
        for (int i = 0; i < nums.size(); ++i) {
            int count = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    count = max(count, dp[j]);
                }
            }
            dp[i] = count + 1;
            maxLIS = max(dp[i], maxLIS);
        }
        return maxLIS;
    }
};
