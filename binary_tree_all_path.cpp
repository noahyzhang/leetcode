// 求二叉树的所有路径


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        if(root == NULL)
            return vec;
        stack<TreeNode*> st1;
        stack<string> st2;
        st1.push(root);
        st2.push(to_string(root->val));
        while(!st1.empty())
        {
            TreeNode* node = st1.top();
            st1.pop();
            string path = st2.top();
            st2.pop();

            if(node->left == NULL && node->right == NULL)
                vec.push_back(path);
            if(node->right != NULL) 
            {
                st1.push(node->right);
                st2.push(path + "->" + to_string(node->right->val));
            }
            if (node->left != NULL)
            {
                st1.push(node->left);
                st2.push(path + "->" + to_string(node->left->val));
            }
        }
        return vec;
    }
};


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        if (root == NULL)
            return vec;
        queue<TreeNode*> qu1;
        queue<string> qu2;
        qu1.push(root);
        qu2.push(to_string(root->val));
        while(!qu1.empty())
        {
            TreeNode* node = qu1.front();
            qu1.pop();
            string path = qu2.front();
            qu2.pop();
            if(node->left == NULL && node->right == NULL)
                vec.push_back(path);
            if(node->right != NULL)
            {
                qu1.push(node->right);
                qu2.push(path + "->" + to_string(node->right->val));
            }
            if(node->left != NULL)
            {
                qu1.push(node->left);
                qu2.push(path + "->" + to_string(node->left->val));
            }
        }
        return vec;
    }
};
