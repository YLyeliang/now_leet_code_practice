// created by yel on 2022/4/4

// Design a data structure that follows the constraints of a Least Recently Used
// (LRU) cache.
// Implement the LRUCache class:
//
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise
// return -1.
// void put(int key, int value) Update the value of the key if the
// key exists. Otherwise, add the key-value pair to the cache. If the number of
// keys exceeds the capacity from this operation, evict the least recently used
// key. The functions get and put must each run in O(1) average time complexity.
//
// Example 1:
//
// Input
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
//[null, null, null, 1, null, -1, null, -1, 3, 4]
// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4
//
// Constraints:
// 1 <= capacity <= 3000
// 0 <= key <= 104
// 0 <= value <= 105
// At most 2 * 105 calls will be made to get and put.

// 问题：实现一个数据结构,遵循Least Recently Used(LRU) cache限制.其成员函数包含
// - LRUcache()初始化LRU缓存，设置capacity容量
// - get. 返回key对应的值
// - put 更新key对应的值，如果超出容量，则删除最近使用最少的key

// 方法：有一个capacity变量来控制容量大小；内部实现一个哈希表+ Double linked
// list. 其中，链表中存pair<int,int>，分别表示key & val.哈希表存key:
// list::iterator. 链表头部存最近使用过的点，尾部存使用最少的点
// 对于put函数，检查哈希表中是否存在key;如果存在，则更新对应的list,将key对应的节点移到链表头部,
// 同时更新链表的值.
// 如果不存在key,判断是否超出容量，如果超出容量，则删除list尾部的节点以及对应在哈希表中的key.
// 在list头部添加节点，同时更新哈希表key:迭代器

#include <list>
#include <unordered_map>

#include "iostream"
using namespace std;

class LRUCache {
  size_t m_capacity;
  unordered_map<int, list<pair<int, int>>::iterator> m_map;
  list<pair<int, int>> m_list;

 public:
  LRUCache(int capacity) : m_capacity(capacity) {}

  int get(int key) {
    auto iter = m_map.find(key);
    if (iter == m_map.end()) return -1;                   // not exist
    m_list.splice(m_list.begin(), m_list, iter->second);  // move node to front.
    return iter->second->second;
  }

  void put(int key, int value) {
    auto iter = m_map.find(key);
    if (iter != m_map.end()) {  // exist
      // update the list position & val
      m_list.splice(m_list.begin(), m_list, iter->second);
      iter->second->second = value;
      return;
    }
    // if exceeds the capacity
    if (m_map.size() == m_capacity) {
      // remove tail key
      int key_to_del = m_list.back().first;
      m_list.pop_back();
      m_map.erase(key_to_del);
    }
    // put value
    m_list.emplace_front(key, value);
    m_map[key] = m_list.begin();
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */