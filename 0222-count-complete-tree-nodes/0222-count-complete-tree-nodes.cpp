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
    
    int leftH(TreeNode* root){
        int cnt = 0;
        while(root){
            cnt++;
            root = root->left;
        }
        return cnt;
    }
    
    int rightH(TreeNode* root){
        int cnt = 0;
        while(root){
            cnt++;
            root = root->right;
        }
        return cnt;
    }
    
    int countNodes(TreeNode* root) {
        //Base Condition
        if(root == NULL){
            return 0;
        }
        
        //Caclulation
        int lh = leftH(root);
        int rh = rightH(root);
        
        if(lh == rh) return (1<<lh)-1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};