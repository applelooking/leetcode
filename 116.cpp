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
        while (root) {
            TreeLinkNode* next = root->left;
            while (root && root->left) {
                root->left->next = root->right;
                root->right->next = root->next ? root->next->left : NULL;
                root = root->next;    
            }
            root = next;
        }
    }
};