class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        for (int i = 0;i < min(s.size(), t.size());++i) {
            if (s[i] == t[i]) continue;
            else {
                return s.substr(i + 1) == t.substr(i + 1) || s.substr(i + 1) == t.substr(i) || s.substr(i) == t.substr(i + 1);
            }
        }
        return abs(int(s.size()) - int(t.size())) == 1;
    }
};