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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return vector<string>();
        if (!root->left && !root->right) return {to_string(root->val)};
        vector<string> result;
        if (root->left) {
            for (auto str : binaryTreePaths(root->left)) {
                result.push_back(to_string(root->val) + "->" + str);
            }
        }
        if (root->right) {
            for (auto str : binaryTreePaths(root->right)) {
                result.push_back(to_string(root->val) + "->" + str);
            }
        }
        return result;
    }
};