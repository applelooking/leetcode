class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mapping;
        for (auto ch : s) {
            mapping[ch]++;
        }
        int result = 0;
        for (auto it : mapping) {
            if (it.second % 2 == 0) {
                result += it.second;
            } else {
                result += it.second - 1;
            }
        }
        return result == s.size() ? result : result + 1;
    }
};