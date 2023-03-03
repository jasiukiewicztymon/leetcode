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
    std::vector<int> nums;
    void bts(TreeNode* node) {
        if (!node)
            return;
        bts(node->left);
        nums.push_back(node->val);
        bts(node->right);
    }
    bool isValidBST(TreeNode* root) {
        bts(root);

        for (int i = 0; i < nums.size() - 1; i++) 
            if (nums[i] >= nums[i + 1])
                return false;
        
        return true;
    }
};
