//LeetCode - problem 230 - Kth Smallest Element in a BST

void inorder(TreeNode* root, vector<int> &res){
        if(!root)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right,res);
        
    }
int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return -1;
        vector<int> arr;
        inorder(root, arr);
        return arr[k-1];

    }
