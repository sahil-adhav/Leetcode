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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int ans = 0;
        
        while(curr != NULL){
            if(curr->left == NULL){
                if(k == 1){
                    ans = curr->val;
                }
                k--;
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    if(k == 1){
                        ans = curr->val;
                    }
                    k--;
                    prev->right = NULL;
                    curr  = curr->right;
                }
            }
        }
        return ans;
    }
};