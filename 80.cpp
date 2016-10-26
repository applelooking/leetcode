class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        for (fast = 0; fast < nums.size();++fast) {
            if (slow < 2 || (nums[fast] != nums[slow - 1] || nums[fast] != nums[slow - 2])){
                swap(nums[slow++], nums[fast]);
            }
        }
        return slow;
    }
};