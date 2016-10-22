class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int ptr1 = INT_MAX;
        int ptr2 = INT_MAX;
        for (auto num : nums) {
            if (num > ptr2) return true;
            if (num < ptr1) ptr1 = num;
            else if (num < ptr2 && num > ptr1) ptr2 = num;
        }
        return false;
    }
};