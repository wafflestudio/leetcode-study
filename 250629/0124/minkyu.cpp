#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 
class Solution {
private:
    int partialMaximum(TreeNode* node, int* answer) {
        if (node == nullptr) return 0;

        int leftMax = partialMaximum(node->left, answer);
        int rightMax = partialMaximum(node->right, answer);

        // nodeMax is the maximum value of path sums which consist of current nodes and descendants of current nodes.
        int nodeMax = node->val;
        if (leftMax > 0) nodeMax += leftMax;
        if (rightMax > 0) nodeMax += rightMax;

        *answer = max(*answer, nodeMax);
        // Return value is the maximum value of path sums which consist of current nodes and at most one child with his descendants.
        return node->val + max({leftMax, rightMax, 0});
    }

public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int* answer = new int(numeric_limits<int>::min());
        partialMaximum(root, answer);
        return *answer;
    }
};
