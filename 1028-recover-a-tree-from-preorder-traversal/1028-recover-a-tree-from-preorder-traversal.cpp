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
    int getVal(string s , int& pos, int n){
        int val = 0;
        while(pos < n && s[pos] != '-'){
            val = val*10 + s[pos]-'0';
            pos++;
        }
        return val;
    }

    int cntDash(string s, int& pos, int n){
        int cnt = 0;
        while(pos<n && s[pos]=='-'){
            pos++;
            cnt++;
        }
        return cnt;
    }

    void buildTree(int expDash, string s, int& pos, TreeNode* curr, int n){
        if(pos == n) return;

        int prev = pos;
        int dashLen = cntDash(s,pos,n);

        if(dashLen  < expDash){
            pos = prev;
            return;
        }
        int val = getVal(s,pos,n);
        TreeNode* newNode = new TreeNode(val);
        if(curr->left == NULL){
            curr->left = newNode;
        }else{
            curr->right = newNode;
        }
        buildTree(expDash+1, s, pos,newNode , n );
        buildTree(expDash+1, s, pos,newNode , n );
    }

    TreeNode* recoverFromPreorder(string s) {
        int n = s.size();
        int pos = 0;
        int val = getVal(s, pos ,n);
        TreeNode* root = new TreeNode(val);
        buildTree(1,s, pos, root, n);
        buildTree(1,s, pos, root, n);
        
        return root;
    }
};