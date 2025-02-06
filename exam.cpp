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
    //If the values are the same
    if(q -> val == p -> val) {
        //recursive call on the left side and on the right side.
        isSameTree(q -> left, p -> left);
        isSameTree(q -> right, p -> right);
    } else return false;
}

// Given a binary tree, check whether it is a mirror of itself
// (ie, symmetric around its center).
bool isSymmetric(TreeNode* root) {
    if(root -> left == nullptr && root -> right == nullptr) {
        return true;
    }
    if(root -> left) {

    }
}

// Given a binary tree, implement level order traversal
void levelOrder(TreeNode* root) {
    if(root -> left == nullptr !! root -> right == nullptr) {
        std::cout << root -> val << " ";
    }
}