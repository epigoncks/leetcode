/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL){
            return true;
        }

        int leftheight = getHeight(root->left);
        int rightheight = getHeight(root->right);

        if(abs(leftheight - rightheight) > 1){
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);

        
    }
    private:
        int getHeight(TreeNode* r){
            if(r == NULL){
                return 0;
            }

            int left = getHeight(r->left);
            int right = getHeight(r->right);

            return max(left, right) + 1;
        }
};