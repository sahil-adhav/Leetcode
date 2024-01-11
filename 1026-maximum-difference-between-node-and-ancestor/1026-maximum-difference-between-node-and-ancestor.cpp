class Solution {
public:
    int solve1(TreeNode* root, int& ans) {
        if(root == NULL) {
            return -1;
        }

        int left = solve1(root->left, ans);
        int right = solve1(root->right, ans);

        if(left == -1 and right == -1)
            return root->val;
        else if(left == -1)
            ans = max({ans,  abs(root->val - right)});
        else if(right == -1)
            ans = max({ans,  abs(root->val - left)});
        
        else ans = max({ans, abs(root->val - left), abs(root->val - right)});

        return max({root->val, left, right});
    }

    int solve2(TreeNode* root, int& ans) {
        if(root == NULL) {
            return 1e7;
        }

        int left = solve2(root->left, ans);
        int right = solve2(root->right, ans);

        if(left == 1e7 and right == 1e7)
            return root->val;
        else if(left == 1e7)
            ans = max({ans,  abs(root->val - right)});
        else if(right == 1e7)
            ans = max({ans,  abs(root->val - left)});
        
        else ans = max({ans, abs(root->val - left), abs(root->val - right)});

        return min({root->val, left, right});
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        solve1(root, ans);
        solve2(root, ans);
        return ans;
    }
};
