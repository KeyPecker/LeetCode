// 617. Merge Two Binary Trees

//
// Revisit this code and optimize as much as possible
//
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
void PrintTreeLevel(TreeNode* root1, TreeNode* root2) {
    if(root1 != NULL || root2 != NULL) {
        std::cout << (root1 != NULL ? root1->val : 0) + (root2 != NULL ? root2->val : 0) << std::endl;
        PrintTreeLevel(root1 != NULL ? root1->left : NULL, root2 != NULL ? root2->left : NULL);
        PrintTreeLevel(root1 != NULL ? root1->right : NULL, root2 != NULL ? root2->right : NULL);
    }
}
*/

void PrintTreeLevel(TreeNode* root) {
    if(root != NULL) {
        std::cout << root->val << std::endl;
        PrintTreeLevel(root->left);
        PrintTreeLevel(root->right);
    }
}
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // corner case
        // this took 48 ms
        if(t1 == NULL && t2 == NULL)  return NULL;
        TreeNode* root = new TreeNode((t1 != NULL ? t1->val : 0) + (t2 != NULL ? t2->val : 0));
        root->left = mergeTrees(t1 == NULL ? NULL : t1->left, t2 == NULL ? NULL : t2->left);
        root->right = mergeTrees(t1 == NULL ? NULL : t1->right, t2 == NULL ? NULL : t2->right);
        return root;

        // try to reuse the nodes
    }
};

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    PrintTreeLevel(root1);
    std::cout << std::endl;
    PrintTreeLevel(root2);
    std::cout << std::endl;

    Solution s;

    PrintTreeLevel(s.mergeTrees(root1, root2));
}