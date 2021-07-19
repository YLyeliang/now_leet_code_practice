//
// Created by yel on 2021/7/18.
//

// Design a HashSet without using any built-in hash table libraries.
//
//Implement MyHashSet class:
//
//void add(key) Inserts the value key into the HashSet.
//bool contains(key) Returns whether the value key exists in the HashSet or not.
//void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

// 问题:实现一个哈希集合,不适用任何内置库
//
// leetcode方法：使用二叉搜索树（BST）。
#include "iostream"

using namespace std;
static const int _ = []() {
    ios::sync_with_stdio(false); // 取消cin和std的同步，默认状态下是开启的，这样保证cin和stdin在混着用时文件指针不会错乱，但会导致cin速度变慢。取消后会加快cin速度。
    cin.tie(nullptr);
    return 0;
}();

// 二叉搜索树的节点定义
struct MyHashSetNode {
    int val;
    MyHashSetNode *left, *right;

    MyHashSetNode(int val) : val(val), left(nullptr), right(nullptr) {}

    ~MyHashSetNode() {
        if (left != nullptr) delete left;
        if (right != nullptr) delete right;
    }
};

// 二叉搜索树
class MyHashSetTree {
private:
    MyHashSetNode *root;
public:
    MyHashSetTree() : root(nullptr) {}

    ~MyHashSetTree() {
        if (root != nullptr)
            delete root; // 迭代调用节点的析构函数来释放资源
    }

    // 插入节点
    MyHashSetNode *Insert(int x, MyHashSetNode *parent) {
        MyHashSetNode *res = parent;
        if (parent == nullptr) {
            res = new MyHashSetNode(x);
        } else if (x < parent->val) {
            parent->left = Insert(x, parent->left);
        } else if (x > parent->val) {
            parent->right = Insert(x, parent->right);
        } else {
            return nullptr; // 重复
        }
        return res;
    }

    // 判断能否插入该值
    bool Insert(int x) {
        if (Find(x) != nullptr)
            return false;

        root = Insert(x, root);
        return true;
    }

    MyHashSetNode *Find(int x, MyHashSetNode *parent) {
        MyHashSetNode *current = parent;
        int current_val;

        while (current != nullptr) {
            current_val = current->val;
            if (x < current_val)
                current = current->left;
            else if (x > current_val)
                current = current->right;
            else
                return current;
        }
        return nullptr;
    }

    MyHashSetNode *Find(int x) {
        if (root == nullptr)
            return nullptr;

        return Find(x, root);
    }

    // 找到最小值，不存在则返回nullptr
    MyHashSetNode *FindMin(MyHashSetNode *parent) {
        MyHashSetNode *current = parent;
        if (current != nullptr) {
            while (current->left)
                current = current->left;
        }
        return current;
    }

    // 删除最小值
    MyHashSetNode *RemoveMin(MyHashSetNode *parent) {
        if (parent == nullptr) { // 节点为空 返回空
            return nullptr;
        } else if (parent->left) { // 节点有左子树，则递归调用删除最小的节点，并将结果返回给左子树
            parent->left = RemoveMin(parent->left);
            return parent;
        } else {
            MyHashSetNode *result = parent->right;
            parent->right = parent->left = nullptr;
            delete parent;
            return result;
        }
    }

    // 删除值为x的节点
    MyHashSetNode *Remove(int x, MyHashSetNode *parent) {
        MyHashSetNode *current = parent;
        MyHashSetNode *left = nullptr;
        MyHashSetNode *right = nullptr;

        int current_val;
        if (current == nullptr) {
            return nullptr;
        } else {
            left = current->left;
            right = current->right;
            current_val = current->val;
        }

        if (x < current_val) {
            current->left = Remove(x, left);
        } else if (x > current_val) {
            current->right = Remove(x, right);
        } else if (left != nullptr && right != nullptr) {
            current->val = FindMin(right)->val;
            current->right = RemoveMin(right);
        } else {
            current = (left != nullptr) ? left : right;

            parent->right = parent->left = nullptr;
            delete parent;
        }
        return current;
    }

    bool Remove(int x) {
        if (Find(x) == nullptr)
            return false;
        root = Remove(x, root);
        return true;
    }

};

class MyHashSet {
private:
    MyHashSetTree tree;
public:
    /** Initialize your data structure here. */
    MyHashSet() {

    }

    void add(int key) {
        tree.Insert(key);
    }

    void remove(int key) {
        tree.Remove(key);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return tree.Find(key) != nullptr;
    }

private:

};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */