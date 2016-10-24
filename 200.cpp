class Solution {
public:
    void DFS(vector<vector<char>>& grid, int x, int y) {
        // grid[x][y] = '0';
        int delta[5] = {0, 1, 0, -1, 0};
        for (int i = 0;i < 4;++i) {
            int new_x = x + delta[i];
            int new_y = y + delta[i + 1];
            if (new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size()) {
                if (grid[new_x][new_y] == '1'){
                    grid[new_x][new_y] = '0';
                    DFS(grid, new_x, new_y);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int result = 0;
        for (int i = 0;i < grid.size();++i) {
            for (int j = 0;j < grid[0].size();++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    result++;
                    DFS(grid, i, j);
                }
            }
        }
        return result;
    }
};