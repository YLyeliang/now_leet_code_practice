#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



// bst 框架。二叉树算法设计总思路：明确一个节点需要做的事情，剩下的交给框架
void traverse(TreeNode root){
    // root 需要做的事情
    // 其它的不用root操心，留给框架
    traverse(root.left);
    traverse(root.right);
};

// 1.给二叉树的所有结点加一
void plusOne(TreeNode root){
    if (root == nullptr) return;
    root.val+=1;

    plusOne(root.left);
    plusOne(root.right);
};

// 2.如何判断两颗二叉树是否相同
void isSameTree(TreeNode root1, TreeNode root2) {
    // both null then true;
    if (root1==NULL && root2==NULL) return true;
    // one null and the other not null then false;
    if (root1 ==NULL || root2 ==NULL) return false;
    // both not null but val is different then false;
    if (root1.val !=root2.val) return false;
    // 剩下的留给框架
    return isSameTree(root1.left,root2.left) &&
    isSameTree(root1.right,root2.right);
};

// 判断BST是否合理
// 错误代码，只考虑了单个结点。很可能某一个结点满足条件，但是对于整体来说不满足。
boolean isValidBST(TreeNode root){
    if (root == NULL) return true;
    if (root.left ==NLL && root.right ==NULL) return true;
    if (root.left !=NULL && root.right !=NULL) return root.left.val<=root.val<=root.right.val;
    if (root.left !=NULL) return root.left.val <=root.val;
    if (root.right !=NULL) return root.right.val >=root.val;

    return isValidBST(root.left) && isValidBST(root.right);
};

// 修改版，root需要做的不止是和左右子节点比较，而是要整个左子树和右子树所有结点比较
// 使用辅助函数，增加函数参数列表，在参数中携带额外信息

boolean isValidBST(TreeNode root){
    return isValidBST(root,NULL,NULL);
}

boolean isValidBST(TreeNode root,TreeNode min,TreeNode max){
    if (root ==NULL) return true;
    if (min !=NULL && root.val<=min.val) return false;
    if (max !=NULL && root.val>=max.val) return false;
    return isValidBST(root.left,min,root) && isValidBST(root.right,root,max)
}

//一、 在BST中查找一个数是否存在
boolean isInBST(TreeNode root,int target){
    if (root == NULL) return false;
    if (root.val== target) return true;
    return isInBST(root.left,target) || isInBST(root.right,target);
};
//上述方法没有利用BST的特性，左小右大。
// 导致速度过慢，合理地利用BST的特性，类似二分搜索，能加快查找速度
boolean isInBST(TreeNode root, int target){
    if (root==NULL) return false;
    if ( root.val==target) return true;
    if (root.val<target) return isInBST(root.right,target);
    if (root.val>target) return isInBST(root.left,target);
}
//得到BST的遍历框架
void BST(TreeNode root, int target){
    if (root.val==target)
    // 找到目标，执行动作
    if (root.val<target)
        BST(root.right,target);
    if (root.val>target)
        BST(root.left,target);

}

//二、在BST中插入一个数
TreeNode insertIntoBST(TreeNode root,int val){
    //找到空位置插入新节点
    if (root ==NULL) return new TreeNode(val);
    // if (root.val==val)
    // BST中一般不会插入已存在的元素
    if (root.val < val)
        root.right=insertIntoBST(root.right,val);
    if (root.val>val)
        root.left=insertIntoBST(root.left,val);
    return root;
};

//三、在BST中删除一个数
TreeNode deleteNode(TreeNode root, int key){
    if (root.val == key){
        //bingo,删除
    }
    else if (root.val >key){
        root.left=deleteNode(root.left,key);
    }
    else if (root.val < key){
        root.right=deleteNode(root.right,key);
    }
    return root;
// 找到结点A之后，如何删除是一个难点。因为删除的同时不能破坏BST的性。一共又三种情况
// 1. A为末端结点，两个子节点为空，就地火化
if( root.left == NULL && root.right==NULL)
    return NULL;

//2. A只有一个非空子节点，这个时候让子节点进行替换
// 排除情况1之后
if (root.left==NULL) return root.right;
if (root.right=NULL) return root.left;

//3. 最复杂的一种，有两个子节点，解决方式有2种：
//A找到左子树中最大的子节点
//A找到右子树中最小的子节点
//以第二种为例
if (root.left !=NULL && root.right !=NULL){
    // 找到右子树的最小结点
    TreeNode minNode= getMin(root.right);
    // 把root改成minNode
    root.val = minNode.val;
    // 删掉minNode
    root.right = deleteNode(root.right, minNode.val);
};

// 将三种情况进行整合，填入框架并简化
TreeNode deleteNode(TreeNode root, int key) {
    if (root==NULL) return NULL;
    if (root.val ==key){
        // 同时处理情况1和2
        if (root.left==NULL) return root.right;
        if (root.right==NULL) return root.left;
        // 情况3
        TreeNode minNode=getMin(root.right);
        root.val=minNode.val;
        root.right=deleteNode(root.right,minNode.val);
    } else if (root.val> key) {
        root.left=deleteNode(root.left,key);
    } else if (root.val<key) {
        root.right=deleteNode(root.right,key);
    }
    return root;
}

TreeNode getMin(TreeNode node) {
    // 最左边的就是最小的
    if (node==NULL) return node;
    return getMin(node.left);
    // 或者
    while (node.left !=NULL) node = node.left;
    return node;
}

// 上述为删除操作，但是实际应用中，一般不会通过root.val=minNode.val修改结点内部的值来交换结点，
// 因为val的域可能很大，操作比较费时。实际应用中一般通过略复杂的链表操作交换root和minNode两个结点，
// 这样，只需要修改指针的指向即可。
//
// 总结
// 二叉树算法设计的总路线：把当前节点要做的事做好，其他的交给递归框架，不用当前节点操心。
//
// 如果当前节点会对下面的子节点有整体影响，可以通过辅助函数增长参数列表，借助参数传递信息。
//
// 在二叉树框架之上，扩展出一套 BST 遍历框架：
void BST(TreeNode root, int target) {
        if (root.val == target)
            // 找到目标，做点什么
        if (root.val < target) 
            BST(root.right, target);
        if (root.val > target)
            BST(root.left, target);
}


int main(){
    int i;
    
}
