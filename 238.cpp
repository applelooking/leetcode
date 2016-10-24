class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) return vector<int>();
        vector<int> result(nums.size(), 1);
        int cur = nums[0];
        for (int i = 1;i < nums.size();++i) {
            result[i] *= cur;
            cur *= nums[i];
        }
        cur = nums.back();
        for (int i = nums.size() - 2;i >= 0;--i) {
            result[i] *= cur;
            cur *= nums[i];
        }
        return result;
    }
};