class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0;i < nums.size();++i) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int target = 0 - nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            while (front < back) {
                int tmp = nums[front] + nums[back];
                if (tmp > target) --back;
                else if (tmp < target) ++front;
                else {
                    vector<int> res = {nums[i], nums[front], nums[back]};
                    result.push_back(res);
                    ++front; --back;
                    while (nums[front] == nums[front - 1] && front < back) ++front;
                    while (nums[back] == nums[back + 1] && back > front) --back;
                }
            }
        }
        return result;
    }
};