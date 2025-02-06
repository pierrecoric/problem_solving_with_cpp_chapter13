#include <queue>
#include <iostream>
using std::queue;
using std::cout;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

// Given two binary trees, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical
// and the nodes have the same value.
bool isSameTree(TreeNode* p, TreeNode* q) {
    //If they are both empty.
    //Base case of the recursion.
    if(!p && !q) {
        return true;
    }
    if(!p || !q) {
        return false;
    }
    if(p -> val != q -> val) {
        return false;
    }
    return (isSameTree(p->left, q->left) && (p -> right, q -> right));
}

// Given a binary tree, check whether it is a mirror of itself
// (ie, symmetric around its center).

bool isMirror(TreeNode* a, TreeNode* b) {
    if(!a && !b) {
        return true;
    }
    if(!a || !b) {
        return false;
    }
    return (a -> val == b -> val && isMirror(a -> right, b -> left) && isMirror(a -> left, b -> right));
}

bool isSymmetric(TreeNode* root) {
    if(!root) {
        return true;
    }
    return isMirror(root -> left, root -> right);
}

// Given a binary tree, implement level order traversal
void levelOrder(TreeNode* root) {
    if(!root) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node -> val << " ";

        if(root -> left) {
            q.push(node -> left);
        }

        if(root -> right) {
            q.push(node -> right);
        }
        
    }
}