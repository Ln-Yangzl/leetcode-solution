#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// in-order traversal to find two wrong pos
class Solution {
    TreeNode* prev;
    TreeNode* first;
    TreeNode* second;
public:
    void recoverTree(TreeNode* root) {
        dfs(root);
        
        swap(first->val, second->val);
    }
    
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        
        dfs(root->left);
        
        if (prev && !first && prev->val > root->val) {
            first = prev;
        }
        
        if (first && prev->val > root->val) {
            second = root;
        }
        
        prev = root;
        
        dfs(root->right);
    }
};