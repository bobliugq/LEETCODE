// Date:        2020.4.9
// Topic:       Array + DP
// Todo:        Optimization
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty() || envelopes[0].empty()) {
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            else return a[0] < b[0];
        });
        int n = envelopes.size();
        int maxLIS = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    count = max(count, dp[j]);
                }
            }
            dp[i] = count + 1;
            maxLIS = max(maxLIS, dp[i]);
        }
        return maxLIS;
    }
};
