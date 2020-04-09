class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)  {
            return {};
        }
        sort(nums.begin(), nums.end());
        if (nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] < 0) {
           return {};
        }
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int target = -nums[i];
            int low = i + 1, high = nums.size() - 1;
            while (low < high) {
                if (nums[low] + nums[high] == target) {
                    res.push_back({nums[i], nums[low], nums[high]});
                    while (low < high && nums[low] == nums[low + 1]) ++low;
                    while (low < high && nums[high] == nums[high - 1]) --high;
                    ++low, --high;
                } else if (nums[low] + nums[high] < target) {
                    while (low < high && nums[low] == nums[low + 1]) ++low;
                    ++low;
                } else if (nums[low] + nums[high] > target) {
                    while (low < high && nums[high] == nums[high - 1]) --high;
                    --high;
                }
            }
        }
        return res;
    }
};
