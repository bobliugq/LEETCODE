class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }
        int n = s.size();
        int maxLen = 1;
        int start = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // k = 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        // k = 2
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }
        // k >= 3
        for (int k = 3; k <= n; ++k) {
            for (int i = 0; i < n - k + 1; ++i) {
                int j = i + k - 1;                // Only compare the two end
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLen = k;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
