class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ptr1 = 0, ptr2 = 0;
        int sum = 0;
        // if (nums.empty()) return 0;
        int result = INT_MAX;
        for (int ptr2 = 0;ptr2 < nums.size();++ptr2) {
            sum += nums[ptr2];
            while (ptr1 <= ptr2 && sum >= s) {
                result = min(result, ptr2 - ptr1 + 1);
                sum -= nums[ptr1++];
            }
        }
        return result > nums.size() ? 0 : result;
    }
};