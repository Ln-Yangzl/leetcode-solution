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

// in-order travasal to judge cur->val > prev->val
bool isValidBST(TreeNode* root) {
    TreeNode* prev = NULL;
    return validate(root, prev);
}
bool validate(TreeNode* node, TreeNode*& prev) {
    if (node == NULL) return true;
    if (!validate(node->left, prev)) return false;
    if (prev != NULL && prev->val >= node->val) return false;
    prev = node;
    return validate(node->right, prev);
}