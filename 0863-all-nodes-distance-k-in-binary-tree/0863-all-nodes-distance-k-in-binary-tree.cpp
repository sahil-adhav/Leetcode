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
private:
    void bfs(TreeNode* root,unordered_map<TreeNode*, TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent_track[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        bfs(root, parent_track);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        
        while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k) break;
            for(int i=0; i<size; i++){
                TreeNode* currNode = q.front();
                q.pop();
                if(currNode->left && !visited[currNode->left]){
                    q.push(currNode->left);
                    visited[currNode->left] = true;
                }
                if(currNode->right && !visited[currNode->right]){
                    q.push(currNode->right);
                    visited[currNode->right] = true;
                }
                if(parent_track[currNode] && !visited[parent_track[currNode]]){
                    q.push(parent_track[currNode]);
                    visited[parent_track[currNode]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode * curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};