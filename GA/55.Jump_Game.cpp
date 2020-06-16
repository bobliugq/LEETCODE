// Date:        2020.04.12
// Topic:       Array + GA
// Todo:        Figure out the relationship between BFS and GA
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dist = 0;
        for (int i = 0; i <= dist; ++i) {
            dist = max(dist, i + nums[i]);
            if (dist >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};
