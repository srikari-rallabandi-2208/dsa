//LeetCode - problem 515

       vector<int> largestValues(TreeNode* root){
        queue<TreeNode*>q;
        vector<int>op;
        if(!root) return op;
        q.push(root);
        int max=INT_MIN;
        while(!q.empty()){
            int size=q.size();
            for(int i=0; i<size; i++){
                TreeNode* t = q.front();
                q.pop();
                if(t->val>max){
                    max=t->val;
                }
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            op.push_back(max);
            max=INT_MIN;          
        }
        return op;
    }
