/*
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。
如果指定节点没有对应的“下一个”节点，则返回null。
*/

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        //若p有右子树，则直接寻找
        if(p->right!=NULL){
            p=p->right;
            while(p->left!=NULL) p=p->left;
            return p;
        }
        else{
            //p一定没有右子树
            //goLeft指向最近的选择了左子树的结点
            TreeNode* curRoot=root, *goLeft=NULL;
            while(curRoot!=NULL){
                //左孩子是目标结点，直接返回curRoot
                if(curRoot->left==p) return curRoot;

                //右孩子是目标结点
                //由于从goLeft->left到p一直走的右子树且p没有右子树，因此p就是goLeft->left这棵树的最后结点
                //其后继结点是goLeft，若p本就是整个遍历的最后结点，也就是从没有选择走左子树，会返回NULL
                if(curRoot->right==p) return goLeft;
                
                //根据BST性质决定遍历左子树还是右子树
                if(p->val<curRoot->val){
                    goLeft=curRoot;
                    curRoot=curRoot->left;
                } else curRoot=curRoot->right;
            }
            return NULL;
        }
    }

};

//通用的中序后继查找
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p->right!=NULL){
            p=p->right;
            while(p->left!=NULL) p=p->left;
            return p;
        }
        else{
            TreeNode* prev=NULL;
            flag=true;
            prev = inOrder(root, p, prev);
            if(prev==p) return NULL;
            else return prev;
        }
    }
    
    TreeNode* inOrder(TreeNode* root, TreeNode* p, TreeNode* prev){
        //遍历左子树
        if(root->left && flag){
            prev = inOrder(root->left,p,prev);
        }
        //检查根节点的前继
        if(prev==p) {
            flag=false;
            return root;
        }
        else if(flag) prev=root;
        //遍历右子树
        if(root->right && flag){
            prev = inOrder(root->right,p,prev);
        }
        return prev;
    }

private:
    //flag用于指示是否已经找到答案，避免后续返回值被覆盖
    bool flag;
};
