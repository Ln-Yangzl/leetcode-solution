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

void recurion_helper(vector<int>& res, TreeNode* cur) {
    if (cur == nullptr) return;
    recurion_helper(res, cur->left);
    res.push_back(cur->val);
    recurion_helper(res, cur->right);
}
 
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    recurion_helper(res, root);
    return res;
}