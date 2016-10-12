class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapping;
        vector<int> result;
        for (int i = 0;i < nums.size();++i) {
            if (mapping.find(target - nums[i]) != mapping.end()) {
                result = {mapping[target - nums[i]], i};
                break;
            } else {
                mapping[nums[i]] = i;
            }
        }
        return result;
    }
};