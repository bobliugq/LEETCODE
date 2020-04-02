class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = n ? board[0].size() : 0;
        int di[8] = {1, 1, 1, 0, 0, -1, -1, -1};
        int dj[8] = {1, -1,0, -1, 1, 1, -1, 0};
        for (int i = 0; i < n; ++i) {
        	for (int j = 0; j < m; ++j) {
				int live  = 0;
				for (int k = 0; k < 8; ++k) {
					int idx_i = i + di[k], idx_j = j + dj[k];
					if (idx_i < 0 || idx_i >= n || idx_j < 0 || idx_j >= m) continue;
					if (board[idx_i][idx_j] == 1 || board[idx_i][idx_j] == 2) live++;
				}
				if (board[i][j] == 1 && (live < 2 || live > 3)) board[i][j] = 2;
				else if (board[i][j] == 0 && (live == 3)) board[i][j] = 3;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				board[i][j] %= 2;	
			}
		}
    }
};
