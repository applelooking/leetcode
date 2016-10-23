class Solution {
    vector<int> store;
public:
    Solution(vector<int> nums) {
        store = nums;
    }
    
    int pick(int target) {
        int result = -1;
        int count = 1;
        for (int i = 0;i < store.size();++i) {
            if (store[i] == target) {
                int tmp = rand() % count;
                if (tmp == 0) result = i;
                ++count;
            }
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */