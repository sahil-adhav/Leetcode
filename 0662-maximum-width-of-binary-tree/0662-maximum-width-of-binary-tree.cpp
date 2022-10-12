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
    int widthOfBinaryTree(TreeNode* root) {
       int width = 0;
        if(root == NULL){
            return 0;
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int currMin = q.front().second;
            int leftMost, rightMost;
            for(int i=0; i<size; i++){
                int currInd = q.front().second - currMin;
                TreeNode *temp = q.front().first;
                q.pop();
                
                if(i == 0) leftMost = currInd;
                if(i == size-1) rightMost = currInd;
                
                if(temp->left) q.push({temp->left, 2*(long long)currInd+1});
                if(temp->right) q.push({temp->right, 2*(long long)currInd+2});
            }
            
            width = max(width, rightMost-leftMost+1);
        }
        return width; 
    }
};