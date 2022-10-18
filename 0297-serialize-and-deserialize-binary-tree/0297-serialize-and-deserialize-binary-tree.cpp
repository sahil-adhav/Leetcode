/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return !root ? " null" : " " + to_string(root->val) + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return help(ss);
    }
    
    TreeNode *help(istringstream& ss){
        string s;
        ss >> s;
        
        if(s == "null"){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(s));
        root->left = help(ss);        
        root->right = help(ss);
        
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));