class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> store;
        for (auto num : nums) {
            store.insert(num);
        }
        int result = 0;
        for (auto num : nums) {
            if (!store.count(num - 1)) {
                int level = 1;
                while (store.count(num + level)) {
                    ++level;
                }
                result = max(result, level);
            }
        }
        return result;
    }
};