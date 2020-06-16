//给定二叉搜索树的根结点 root，返回 L 和 R（含）之间的所有结点的值的和。
//
//二叉搜索树保证具有唯一的值。
//
// 
//
//示例 1：
//
//输入：root = [10,5,15,3,7,null,18], L = 7, R = 15
//输出：32
//示例 2：
//
//输入：root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
//输出：23

// 1. 暴力解法
// 遍历整个树，并将处在区间内的数全部求和即可。time:O(N) sapce: O(N)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == nullptr) return 0;
        int res=0;
        if ( root->val>=L && root->val <=R) res+=root->val;
        res+=rangeSumBST(root->left,L,R);
        res+=rangeSumBST(root->right,L,R);
        return res;
    }
};

// 2. 根据BST的左小右大的性质进行求解

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == nullptr) return 0;
        if (root->val <L) return rangeSumBST(root->right,L,R);
        if (root->val >R) return rangeSumBST(root->left,L,R);
        return root->val+rangeSumBST(root->left,L,R)+rangeSumBST(root->right,L,R);
    }
};