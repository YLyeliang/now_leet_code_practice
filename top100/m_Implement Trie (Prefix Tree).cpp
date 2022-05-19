// created by yel on 2022/5/19

// A trie (pronounced as "try") or prefix tree is a tree data structure used to
// efficiently store and retrieve keys in a dataset of strings. There are
// various applications of this data structure, such as autocomplete and
// spellchecker.
//
// Implement the Trie class:
//
// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie
// (i.e., was inserted before), and false otherwise. boolean startsWith(String
// prefix) Returns true if there is a previously inserted string word that has
// the prefix prefix, and false otherwise.
//
//
// Example 1:
//
// Input
//["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
//[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
//[null, null, true, false, true, null, true]
//
// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True
//
//
// Constraints:
//
// 1 <= word.length, prefix.length <= 2000
// word and prefix consist only of lowercase English letters.
// At most 3 * 104 calls in total will be made to insert, search, and
// startsWith.

// 问题：前缀树，用于有效地在字符串中存储和检索关键字。应用场景如，拼写检查器、自动补全
// 完成他的功能, Trie() 初始化
// void insert(string word) 插入word到trie
// boolen search(string word)返回true如果存在, false otherwise
// boolean startsWith(string prefix)返回true如果有字符串包含前缀prefix, false
// otherwise.

// 方法：要高效完成插入和检索部分，使用哈希表进行存储.
// 采用哈希表嵌套的方式进行存储。对于字符串prefix以 dict(p =
// dict(r=...))的树状形式进行存储.
// 检索时判断末尾的字符标志符isword是否为true.该标志符在插入字符串时生成
// 判断前缀时则通过在树中遍历前缀字符串即可。

#include <string>

#include "iostream"
#include "map"

using namespace std;

class Trie {
 public:
  Trie() {}

  void insert(string word) {
    Trie* root = this;  // 根节点为{}
    for (char ch : word) {
      // 如果next不存在，即字符还未插入，则生成
      if (!root->next.count(ch)) root->next[ch] = new Trie();
      root = root->next[ch];
    }
    root->isword = true;  // 末尾字符表示字符串结尾
  }

  bool search(string word) {
    Trie* root = this;
    for (auto ch : word) {
      // 如果不存在，则返回false
      if (!root->next.count(ch)) return false;
      root = root->next[ch];
    }
    return root->isword;
  }

  bool startsWith(string prefix) {
    Trie* root = this;
    for (auto ch : prefix) {
      if (!root->next.count(ch)) return false;
      root = root->next[ch];
    }
    return true;
  }

 private:
  map<char, Trie*> next = {};
  bool isword = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */