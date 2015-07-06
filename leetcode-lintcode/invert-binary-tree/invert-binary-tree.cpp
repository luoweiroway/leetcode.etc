// Author : luowei

/*
翻转一棵二叉树

样例:
  1         1
 / \       / \
2   3  => 3   2
   /       \
  4         4
挑战:
    递归固然可行，能否写个非递归的？
*/

class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    
    // 方法一：recursion 1
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        if(root==NULL)
            return ;
        if((root->left)!=NULL || (root->right)!=NULL){
            TreeNode *temp=root->left;
            root->left=root->right;
            root->right=temp;
        }
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
    }
    
    // 方法一：recursion 2
    TreeNode *invertBinaryTree(TreeNode *root) {
        if(root==NULL)
            return NULL;
        if((root->left)!=NULL || (root->right)!=NULL){
            TreeNode *temp=root->left;
            root->left=invertBinaryTree(root->right);
            root->right=invertBinaryTree(temp);
        }
        return root;
    }
    
    // 方法三：non-recursion
    TreeNode *invertBinaryTree(TreeNode *root) {
        queue<TreeNode *> node_queue;
        if(root==NULL)
            return NULL;
        node_queue.push(root);
        while(node_queue.size()>0){
            TreeNode *element=node_queue.front();
            
            TreeNode *temp=element->left;
            element->left=element->right;
            element->right=temp;
            
            node_queue.pop();
            if(element->left)
                node_queue.push(element->left);
            if(element->right)
                node_queue.push(element->right);
        }
        return root;
    }
};


