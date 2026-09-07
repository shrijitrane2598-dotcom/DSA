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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        // tree is empty 
        if(root == NULL) {
            return ans;
        }

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> level;

            //process one compleate level
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                //Add left child
                if(curr->left != NULL) {
                    q.push(curr->left);
                }

                //Add right child
                if(curr->right != NULL) {
                    q.push(curr->right);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};