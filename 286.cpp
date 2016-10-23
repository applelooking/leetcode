class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;
        for (int i = 0;i < rooms.size();++i) {
            for (int j = 0;j < rooms[i].size();++j) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int level = 0;
        int delta[5] = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            ++level;
            int size = q.size();
            for (int i = 0;i < size;++i) {
                auto cur = q.front();
                q.pop();
                //rooms[cur.first][cur.second] = level;
                for (int j = 0;j < 4;++j) {
                    int x = cur.first + delta[j];
                    int y = cur.second + delta[j + 1];
                    if (x >= 0 && x < rooms.size() && y >= 0 && y < rooms[x].size() && rooms[x][y] == INT_MAX) {
                        rooms[x][y] = level;
                        q.push({x, y});
                    } 
                }
            }
        }
    }
};