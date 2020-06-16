class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.empty() && p.empty()) {
            return true;
        }
        if (p.empty()) {
            return false;
        }
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false)); // dp[i][j] == true represent s[0, i - 1] equal p[0, j - 1] 
        // Edge Case
        dp[0][0] = true;               
        // Edge Case
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = false;
        }
        // Edge Case
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = j > 1 && p[j - 1] == '*' && dp[0][j - 2];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] != '*') {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                } else {
                    dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
            }
        }
        return dp[n][m];
    }
};
