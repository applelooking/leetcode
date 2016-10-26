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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> mapping;
        mapping[root] = NULL;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty() && (mapping.find(p) == mapping.end() || mapping.find(q) == mapping.end())) {
            int size = queue.size();
            for (int i = 0;i < size;++i) {
                TreeNode* cur = queue.front();
                queue.pop();
                if (cur->left) {
                    mapping[cur->left] = cur;
                    queue.push(cur->left);
                }
                if (cur->right) {
                    mapping[cur->right] = cur;
                    queue.push(cur->right);
                }
            }
        }
        unordered_set<TreeNode*> set;
        TreeNode* ptr = q;
        while (ptr) {
            set.insert(ptr);
            ptr = mapping[ptr];
        }
        ptr = p;
        while (set.count(ptr) == 0) {
            ptr = mapping[ptr];
        }
        return ptr;
    }
};