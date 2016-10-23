/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> mp;
        vector<vector<int>> result;
        if (!root) return result;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0;i < size;++i) {
                auto tmp = q.front();
                q.pop();
                mp[tmp.second].push_back(tmp.first->val);
                if (tmp.first->left) {
                    q.push({tmp.first->left, tmp.second - 1});
                }
                if (tmp.first->right) {
                    q.push({tmp.first->right, tmp.second + 1});
                }
            }
        }
        for (auto it : mp) {
            result.push_back(it.second);
        }
        return result;
    }
};