// created by yel on 2022/4/8

// There are a total of numCourses courses you have to take, labeled from 0 to
// numCourses - 1. You are given an array prerequisites where prerequisites[i] =
// [ai, bi] indicates that you must take course bi first if you want to take
// course ai.
//
// For example, the pair [0, 1], indicates that to take course 0 you have to
// first take course 1. Return true if you can finish all courses. Otherwise,
// return false.
//
// Example 1:
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0. So it is possible.
//
// Example 2:
//
// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0, and to take course 0 you
// should also have finished course 1. So it is impossible.
//
// Constraints:
//
// 1 <= numCourses <= 105
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.

// 问题：有n门课要上，分别为0 ~ n-1, 有一个条件数组pre, pre[i] = [ai, bi],
// 表示上ai之前必须先上bi.  在给定pre的情况下，求能不能上完所有课.

// 方法：0 1 2 3 4 5 6

// BFS
// 使用拓扑排序的思想，将pre转换为图的方式，
// 1. 找到没有前驱节点的节点
// 2. 消除该节点指向的边
// 3. 重复 1 & 2.  如果找不到没有前驱节点的节点，即图有环，则return false
// 具体实现：构建一个degrees数组，degrees[i]表示节点i的前驱节点数；=0时即为起始点，遍历过后将其置为-1表示已经删除
//

// DFS
// 根据深度优先的思想，
// 1. 从一个节点出发
// 2. 持续访问他的下一个节点
// 3. 如果访问到了已经访问过的节点，则表明有环，return false
// 4. 从一个未访问过的节点出发，重复2 & 3
// 使用todo和 done来表示要访问和已访问的节点

#include "iostream"
#include "vector"

using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    graph g = buildGraph(numCourses, prerequisites);
    vector<int> degrees = computeIndegress(g);
    for (int i = 0; i < numCourses; i++) {
      int j = 0;
      // 遍历degree，找到=0的节点，
      for (; j < numCourses; j++)
        if (!degrees[j]) break;

      // j表示没有前驱节点的节点，如果等于numCourses，即遍历之后没有找到，则有环
      if (j == numCourses) return false;

      // 找到之后，节点置为-1,删除节点指向的对应节点的边，即指向节点的前驱次数-1
      degrees[j]--;
      for (auto p : g[j]) degrees[p]--;
    }
    return true;
  }

 private:
  typedef vector<vector<int>> graph;

  graph buildGraph(int numCourse, vector<vector<int>>& prerequisites) {
    graph g(numCourse);
    for (auto p : prerequisites) g[p[1]].push_back(p[0]);
    return g;
  }

  vector<int> computeIndegress(graph& g) {
    vector<int> degree(g.size(), 0);
    for (auto adj : g)
      for (auto p : adj) degree[p]++;
    return degree;
  }
};

class Solution2 {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    graph g = buildGraph(numCourses, prerequisites);
    vector<int> todo(numCourses, false), done(numCourses, false);
    for (int i = 0; i < numCourses; i++)
      if (!done[i] && !acyclic(g, todo, done, i))
        return false;  // 节点i没有被访问过，且从节点i开始搜索有环
    return true;
  }

 private:
  typedef vector<vector<int>> graph;
  graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
    graph g(numCourses);
    for (auto p : prerequisites) g[p[1]].push_back(p[0]);
    return g;
  }

  bool acyclic(graph& g, vector<int> todo, vector<int> done, int node) {
    if (todo[node]) return false;  // 如果要访问的节点已经访问过，则有环
    if (done[node]) return true;  // 如果节点已经访问过了，没有环
    todo[node] = done[node] = true;
    for (auto v : g[node])  // 从node出发，深度优先
      if (!acyclic(g, todo, done, v)) return false;
    todo[node] = false;
    return true;
  }
};