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

// recursion solution: for i in range(1, n)
// (i->left, i->right) = ans(1, i-1), ans(i+1, n)
//vector<TreeNode*> getAns(int start, int end) {
//    vector<TreeNode*> ans;
//    if (start > end) {
//        ans.push_back(nullptr);
//        return ans;
//    }
//    if (start == end) {
//        ans.push_back(new TreeNode(start));
//        return ans;
//    }
//    for (int i = start; i <= end; i++) {
//        auto leftChild = getAns(start, i - 1);
//        auto rightChild = getAns(i + 1, end);
//        for (auto left : leftChild) {
//            for (auto right : rightChild) {
//                TreeNode* root = new TreeNode(i);
//                root->left = left;
//                root->right = right;
//                ans.push_back(root);
//            }
//        }
//    }
//    return ans;
//}
//
//vector<TreeNode*> generateTrees(int n) {
//    return getAns(1, n);
//}

// dp solution, make recursion bottom up
TreeNode* clone(TreeNode* cur, int offset) {
	if (cur == nullptr) return nullptr;
	TreeNode* node = new TreeNode(cur->val + offset);
	node->left = clone(cur->left, offset);
	node->right = clone(cur->right, offset);
	return node;
}

vector<TreeNode*> generateTrees(int n) {
	vector<vector<TreeNode*>> dp(n + 1, vector<TreeNode*>());
	dp[0] = vector<TreeNode*>(1, nullptr);
	for (int len = 1; len <= n; len++) {
		for (int root = 1; root <= len; root++) {
			int left = root - 1;
			int right = len - root;
			for (auto leftchild : dp[left]) {
				for (auto rightchild : dp[right]) {
					TreeNode* cur_root = new TreeNode(root);
					cur_root->left = leftchild;
					cur_root->right = clone(rightchild, root);
					dp[len].push_back(cur_root);
				}
			}
		}
	}
	return dp[n];
}