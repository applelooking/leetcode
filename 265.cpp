class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int n = costs.size();
        int col = costs[0].size();
        vector<int> result(col, 0);
        int first = 0;
        int second = 0;
        for (int i = 0;i < n;++i) {
            int tmp_first = INT_MAX;
            int tmp_second = INT_MAX;
            for (int j = 0;j < col;++j) {
                if (result[j] == first) {
                    result[j] = second + costs[i][j];
                } else {
                    result[j] = first + costs[i][j];
                }
                if (tmp_first >= result[j]) {
                    tmp_second = tmp_first;
                    tmp_first = result[j];
                } else if (tmp_second > result[j]) {
                    tmp_second = result[j];
                }
            }
            first = tmp_first;
            second = tmp_second;
        }
        return first;
        
    }
};