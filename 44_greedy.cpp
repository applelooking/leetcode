class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        int ptr1 = 0;
        int ptr2 = 0;
        int star = -1;
        int match = 0;
        while (ptr1 < m) {
            if (ptr2 < n && p[ptr2] == '*') {
                match = ptr1;
                star = ptr2++;
            } else if (ptr2 < n && (p[ptr2] == s[ptr1] || p[ptr2] == '?')) {
                ++ptr1;
                ++ptr2;
            } else if (star >= 0) {
                ptr1 = ++match;
                ptr2 = star;
            } else return false;
        }
        while (ptr2 < n && p[ptr2] == '*') ++ptr2;
        return ptr2 == n;
    }
};