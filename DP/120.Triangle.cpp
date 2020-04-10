// Date:        2020.4.10
// Topic:       DP + Array
// Todo:        Optimization + bottom-up method

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty()) {
            return 0;
        }
        int n = triangle.size();
        if (n > 1) {
            triangle[1][0] += triangle[0][0];
            triangle[1][1] += triangle[0][0];
        }
        for (int i = 2; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                } else if (j == i) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
            }
        }
        int res = triangle[n - 1][0];
        for (int i = 1; i < n; ++i) {
            res = min(res, triangle[n - 1][i]);
        }
        return res;
    }
};
