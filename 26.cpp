class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr1 = 0;
        int ptr2 = 0;
        if (nums.empty()) return ptr1;
        while (ptr2 < nums.size()) {
            if (ptr1 != 0 && nums[ptr2] == nums[ptr1 - 1]) {
                ++ptr2;
            } else {
                nums[ptr1++] = nums[ptr2++];
            }
        }
        return ptr1;
    }
};