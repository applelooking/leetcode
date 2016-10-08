class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> right;
        if (nums.empty()) return result;
        int product = 1;
        for (int i = nums.size() - 1;i >= 0;--i) {
            right[i] = product;
            product *= nums[i];
        }
        product = 1;
        for (int i = 0; i < nums.size();++i) {
            result.push_back(product * right[i]);
            product *= nums[i];
        }
        return result;
    }
};