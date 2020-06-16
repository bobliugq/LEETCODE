// Date:        2020.4.12
// Topic:       BFS
// Todo:        Figure out the difference between BFS and GA

class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int curEnd = 0, curFarthest = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            curFarthest = max(curFarthest, i + nums[i]);
            if (i == 0) {
                ++count;
                curEnd = curFarthest;
            }
        }
        return count;
    }
};
