class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0, ptr1 = a.size() - 1, ptr2 = b.size() - 1;
        while (carry != 0 || ptr1 >= 0 || ptr2 >= 0) {
            carry += ptr1 >= 0 ? a[ptr1--] - '0' : 0;
            carry += ptr2 >= 0 ? b[ptr2--] - '0' : 0;
            result = to_string(carry % 2) + result;
            carry /= 2;
        }
        return result;
    }
};