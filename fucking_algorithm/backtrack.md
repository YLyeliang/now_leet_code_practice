回溯问题，实际上就是一个决策树的遍历过程。只需要思考3个问题：
1、路径：也就是已经做出的选择
2、选择列表：当前可做的选择
3、结束条件：到达决策树底层，无法再做选择的条件。

# 框架
result=[]
def backtrack(路径，选择列表):
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表:
        做选择
        backtrack(路径，选择列表)
        撤销选择

核心就是for循环里面的递归，在递归调用之前做选择，在递归调用之后撤销选择。
一、全排列问题
n个不重复的数，全排列有n!个组合。
比如[1,2,3]，固定第一位为1,第二位为2,123;第二位改变为3,132;改变第一位为2,213 & 231...
可以画出回溯树，or 决策树，记录路径上的数字，即为全排列。
 
回溯算法的核心框架
```python
for 选择 in 选择列表:
    # 做选择
    将该选择从选择列表移除
    路径.add(选择)
    backtrack(路径，选择列表)
    # 撤销选择
    路径.remove(选择)
    将该选择再加入选择列表
```
我们只要在递归之前做出选择，在递归之后撤销刚才的选择，就能正确得到每个节点的选择列表和路径。
全排列代码
```java
List<List<Integer>> res = new LinkedList<>();
/* 主函数，输入一组不重复的数字，返回它们的全排列 */
List<List<Integer>> permute(int[] nums) {

```
