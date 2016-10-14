class Solution {
public:
    int numDecodings(string s) {
        int before = 1, prev = 1, cur = 1;
        if (s.empty() || s[0] == '0') return 0;
        for (int i = 1;i < s.size();++i) {
            cur = s[i] == '0' ? 0 : prev;
            int tmp = s[i] - '0' + (s[i - 1] - '0') * 10;
            if (tmp >= 10 && tmp <= 26) {
                cur += before;
            }
            before = prev;
            prev = cur;
        }
        return cur;
    }
};