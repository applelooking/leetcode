class Solution {
public:
    void helper(vector<vector<int>>& result, vector<int>& cur, const vector<int>& nums, int begin) {
        result.push_back(cur);
        for (int i = begin;i < nums.size();++i) {
            if (i != begin && nums[i] == nums[i - 1]) continue;
            cur.push_back(nums[i]);
            helper(result, cur, nums, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        vector<int> cur;
        helper(result, cur, nums, 0);
        return result;
    }
};