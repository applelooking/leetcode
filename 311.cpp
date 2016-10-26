class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.empty() || B.empty()) return vector<vector<int>>();
        vector<vector<int>> result(A.size(), vector<int>(B[0].size(), 0));
        vector<vector<pair<int, int>>> rows(A.size(), vector<pair<int, int>>());
        vector<vector<pair<int, int>>> cols(B[0].size(), vector<pair<int, int>>());
        for (int i = 0;i < A.size();++i) {
            for (int j = 0;j < A[0].size();++j) {
                if (A[i][j] != 0) {
                    rows[i].push_back({j, A[i][j]});
                }
            }
        }
        for (int i = 0;i < B[0].size();++i) {
            for (int j = 0;j < B.size();++j) {
                if (B[j][i] != 0) {
                    cols[i].push_back({j, B[j][i]});
                }
            }
        }
        for (int i = 0;i < A.size();++i) {
            for (int j = 0;j < B[0].size();++j) {
                int ptr1 = 0;
                int ptr2 = 0;
                while (ptr1 < rows[i].size() && ptr2 < cols[j].size()) {
                    if (rows[i][ptr1].first == cols[j][ptr2].first) {
                        result[i][j] += rows[i][ptr1++].second * cols[j][ptr2++].second;
                    } else if (rows[i][ptr1].first < cols[j][ptr2].first) {
                        ++ptr1;
                    } else {
                        ++ptr2;
                    }
                }
            }
        }
        return result;
    }
};