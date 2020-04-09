// Author:      BobLiu
// Date:        2020.4.6
// Todo:        Time and space complexity

class Solution {
    int maxSize = 0, maxCur = 0;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    maxCur = 0;
                    dfs(grid, i, j);
                }
            }
        }
        return maxSize;
    }

    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) return;
        grid[i][j] = 0;
        ++maxCur;
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
        maxSize = max(maxSize, maxCur);
    }
}; 
