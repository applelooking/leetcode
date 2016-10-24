class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> out;
        unordered_map<char, int> in_degree;
        string result = "";
        if (words.empty()) return result;
        if (words.size() == 1) return words[0];
        for (auto word : words) {
            for (auto ch : word) {
                in_degree[ch] = 0;
            }
        }
        for (int i = 1;i < words.size();++i) {
            int j = 0;
            for (;j < min(words[i - 1].size(), words[i].size());++j) {
                if (words[i - 1][j] != words[i][j]) {
                    out[words[i - 1][j]].push_back(words[i][j]);
                    in_degree[words[i][j]]++;
                    break;
                }
            }
            cout<<j<<endl;
            if (j == min(words[i - 1].size(), words[i].size())) {
                if (words[i].size() < words[i - 1].size()) return "";
            }
        }
        queue<char> q;
        for (auto it : in_degree) {
            if (it.second == 0) q.push(it.first);
        }
        while (!q.empty()) {
            char cur = q.front();
            q.pop();
            result += cur;
            for (auto ch : out[cur]) {
                if (--in_degree[ch] == 0) {
                    q.push(ch);
                }
            }
        }
        if (result.size() != in_degree.size()) return "";
        else return result;
    }
};