class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.find(target - nums[i]) != mp.end()) {
                if (mp[target - nums[i]] == i) {         // Avoid Test Case {3, 2, 4} target = 6 
                    continue;
                } else {
                    return {i, mp[target - nums[i]]};
                }
            }
        }
        return {-1, -1};
    }
};
