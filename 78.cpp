class Solution {
public:
    void helper(vector<vector<int>>& result, vector<int>& cur, const vector<int>& nums, int begin) {
        if (begin == nums.size()) {
            result.push_back(cur);
            return;
        }
        for (int i = begin;i < nums.size();++i) {
            cur.push_back(nums[i]);
            helper(result, cur, nums, i + 1);
            cur.pop_back();
        }
        helper(result, cur, nums, nums.size());
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        helper(result, cur, nums, 0);
        return result;
    }
};