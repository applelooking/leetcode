class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> mp(target + 1, 0);
        mp[0] = 1;
        for (int i = 1;i <= target;++i) {
            for (auto num : nums) {
                if (i - num >= 0) mp[i] += mp[i - num];
            }
        }
        return mp[target];
    }
};