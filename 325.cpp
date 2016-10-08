class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> mapping;
        mapping[0] = -1;
        if (nums.empty()) return 0;
        int sum = 0;
        int result = 0;
        for (int i = 0;i < nums.size();++i) {
            sum += nums[i];
            if (mapping.find(sum) == mapping.end()) {
                mapping[sum] = i;
            }
            if (mapping.find(sum - k) != mapping.end()) {
                result = max(i - mapping[sum - k], result);
            }
        }
        return result;
    }
};