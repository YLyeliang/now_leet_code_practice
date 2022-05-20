// created by yel on 2022/5/20

// There are a total of numCourses courses you have to take, labeled from 0 to
// numCourses - 1. You are given an array prerequisites where prerequisites[i] =
// [ai, bi] indicates that you must take course bi first if you want to take
// course ai.
//
// For example, the pair [0, 1], indicates that to take course 0 you have to
// first take course 1. Return the ordering of courses you should take to finish
// all courses. If there are many valid answers, return any of them. If it is
// impossible to finish all courses, return an empty array.
//
// Example 1:
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you
// should have finished course 0. So the correct course order is [0,1].

// Example 2:
// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you
// should have finished both courses 1 and 2. Both courses 1 and 2 should be
// taken after you finished course 0. So one correct course order is [0,1,2,3].
// Another correct ordering is [0,2,1,3]. Example 3:
//
// Input: numCourses = 1, prerequisites = []
// Output: [0]
//
// Constraints:
// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= numCourses * (numCourses - 1)
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// ai != bi
// All the pairs [ai, bi] are distinct.

// 问题： 有n门课要上，分别用0 - n-1来表示.前置数组pre[i] = [ai,
// bi]表示要先上bi才能上ai, 返回上课的顺序，如果不能上完所有课程，返回空

// 方法：与I相比，这里需要返回的是节点数组. 可以采用相同的思想
// 用有向图的方式来进行表示.
// BFS
// 1. 找到没有前驱节点的节点
// 2. 消除该节点指向的边，同时将对应的节点添加到数组中
// 3. 持续1&2，若找不到没有前驱节点的节点，则说明有环，返回空
// 构建一个degrees数组,degrees[i]表示节点i的前驱节点数量，0表示为起点，-1表示已遍历

#include <vector>

#include "iostream"

using namespace std;

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    graph g = buildGraph(numCourses, prerequisites);
    vector<int> res;
    vector<int> degree = computeDegree(g);
    // iteration
    for (int i = 0; i < numCourses; i++) {
      int j = 0;
      // 1. 找没有前驱的节点, degree[i] = 0
      for (; j < numCourses; j++)
        if (!degree[j]) break;

      // 有环
      if (j == numCourses) return {};
      // 2. 节点置为-1,表示已访问，
      degree[j]--;
      // 消除该节点指向的边，然后将结果添加到res中
      for (auto p : g[j]) {
        degree[p]--;
      }
      res.push_back(j);
    }
    return res;
  }

 private:
  typedef vector<vector<int>> graph;
  graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
    graph g(numCourses);
    for (auto p : prerequisites) g[p[1]].push_back(p[0]);
    return g;
  }

  vector<int> computeDegree(graph& g) {
    vector<int> degree(g.size(), 0);
    for (auto adj : g)
      for (auto p : adj) degree[p]++;
    return degree;
  }
};

// DFS
class Solution2 {
 public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    graph g = buildGraph(numCourses, prerequisites);
    vector<int> order;
    vector<bool> todo(numCourses, false), done(numCourses, false);
    for (int i = 0; i < numCourses; i++) {
      if (!done[i] && !acyclic(g, todo, done, i, order)) {
        return {};
      }
    }
    reverse(order.begin(), order.end());
    return order;
  }
 private:
  typedef vector<vector<int>> graph;

  graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
    graph g(numCourses);
    for (auto p : prerequisites) {
      g[p.second].push_back(p.first);
    }
    return g;
  }

  bool acyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node, vector<int>& order) {
    if (todo[node]) {
      return false;
    }
    if (done[node]) {
      return true;
    }
    todo[node] = done[node] = true;
    for (int neigh : g[node]) {
      if (!acyclic(g, todo, done, neigh, order)) {
        return false;
      }
    }
    order.push_back(node);
    todo[node] = false;
    return true;
  }
};