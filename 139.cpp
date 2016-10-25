class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1;i <= s.size();++i) {
            for (int j = 1;j <= i;++j) {
                 if (dp[j - 1]) {
                     if (wordDict.count(s.substr(j - 1, i - j + 1))) {
                         dp[i] = true;
                     }
                 }
            }
        }
        return dp.back();
    }
};