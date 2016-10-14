class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const vector<string> phone_pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        if (digits.empty()) return result;
        result.push_back("");
        for (auto ch : digits) {
            int ptr = ch - '0';
            if (ptr < 0 || ptr > 9) return vector<string>();
            vector<string> tmp;
            for (auto str : result) {
                for (auto alp : phone_pad[ptr]) {
                    tmp.push_back(str + alp);
                }
            }
            result = tmp;
        }
        return result;
    }
};