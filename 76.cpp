class Solution {
public:
    string minWindow(string s, string t) {
        //unordered_map<char, int> mapping;
        vector<int> mapping(128, 0);
        for (auto ch : t) {
            mapping[ch]++;
        }
        int remaining = t.size();
        int first = 0;
        string result = s + 'a';
        for (int i = 0;i < s.size();++i) {
            if (mapping[s[i]] > 0) remaining--;
            --mapping[s[i]];
            while (remaining == 0) {
                result = result.size() > i - first + 1 ? s.substr(first, i - first + 1) : result;
                if (++mapping[s[first]] > 0) {
                    remaining++;
                }
                ++first;
            }
        }
        if (result == s + 'a') return "";
        else return result;
    }
};