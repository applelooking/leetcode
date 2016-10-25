/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode* next = root;
        TreeLinkNode* prev = NULL;
        while (next) {
            root = next;
            next = NULL;
            prev = NULL;
            while (root) {
                if (root->left) {
                    if (next == NULL) next = root->left;
                    if (prev) {
                        prev->next = root->left;
                    }
                    prev = root->left;
                }
                if (root->right) {
                    if (next == NULL) next = root->right;
                    if (prev) {
                        prev->next = root->right;
                    }
                    prev = root->right;
                }
                root = root->next;
            }
        }
        
    }
};