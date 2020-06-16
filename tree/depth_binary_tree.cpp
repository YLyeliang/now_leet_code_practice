

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 一、 DFS
//采用递归的方式进行。 树的深度由左右子树决定，其深度等于左右子树中最深的+1.
//则可得到递归公式max(left,right)+1
// time: O(N) space:O(N)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1
    }
};

//二、 BFS
//树的层序遍历 / 广度优先搜索往往利用 队列 实现。
//关键点： 每遍历一层，则计数器 +1 ，直到遍历完成，则可得到树的深度。
//步骤：
//特例处理： 当 root​ 为空，直接返回 深度 0。
//初始化： 队列 queue （加入根节点 root ），计数器 res = 0。
//循环遍历： 当 queue 为空时跳出。
//初始化一个空列表 tmp ，用于临时存储下一层节点；
//遍历队列： 遍历 queue 中的各节点 node ，并将其左子节点和右子节点加入 tmp；
//更新队列： 执行 queue = tmp ，将下一层节点赋值给 queue；
//统计层数： 执行 res += 1 ，代表层数加 11；
//返回值： 返回 res 即可。

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0; --i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ++ans;
        }
        return ans;
    }
};