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
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        int cnt = 1;
        while(!q.empty()){
            vector<int>arr;
            int c = 0;
            while(cnt>0){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL){
                    q.push(node->left);
                    c++;
                }
                if(node->right != NULL){
                    q.push(node->right);
                    c++;
                }
                cnt--;
                arr.push_back(node->val);
            }
            cnt = c;
            ans.push_back(arr);
        }
        return ans;
    }
};