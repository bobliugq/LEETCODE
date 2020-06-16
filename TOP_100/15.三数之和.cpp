class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] < 0) {
            return {};
        }
        for (int i = 0; i < nums.size() - 2; ++i) {
            // Edge Case : [0, 0, 0, 0]
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                if (nums[start] + nums[end] == target) {
                    res.push_back({nums[i], nums[start], nums[end]});
                    while (start < end && nums[start] == nums[start + 1]) ++start;
                    ++start;
                    while (start < end && nums[end] == nums[end - 1]) --end;
                    --end;
                } else if (nums[start] + nums[end] < target) {
                    while (start < end && nums[start] == nums[start + 1]) ++start;
                    ++start;
                } else if (nums[start] + nums[end] > target) {
                    while (start < end && nums[end] == nums[end - 1]) --end;
                    --end;
                }
            }
        }
        return res;
    }
};
