// Date:    2020.4.10
// Topic:   Array + Sort
// Todo:    Time and Space optimiztion
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end(), [] (auto& a, auto& b) {return a[0] < b[0];});
        int start = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> res;
        for (int i = 1; i < intervals.size(); ++i) {
            if (end >= intervals[i][0]) {
                end = max(end, intervals[i][1]);
            } else {
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        res.push_back({start, end});
        return res;
    }
};
