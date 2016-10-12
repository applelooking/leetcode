class Solution {
public:
    bool isValid(string s) {
        stack<char> stacking;
        for (int i = 0;i < s.size();++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] =='{') stacking.push(s[i]);
            else {
                if (stacking.empty()) return false;
                if (stacking.top() == '(' && s[i] ==')') stacking.pop();
                else if (stacking.top() == '[' && s[i] == ']') stacking.pop();
                else if (stacking.top() == '{' && s[i] == '}') stacking.pop();
                else return false;
            }
        }
        return stacking.empty();
    }
};