// Two sum I:
// 在leetcode和一些常见面试题中出现，基本形式如下：
// 给定一个数组和一个整数target，可以保证数组中存在两个数的和为target,并返回这两个数的索引。
// e.g: nums=[3,1,3,6],target=6.返回[0,2] 3+3=6。
//
//暴力解法：使用两个for 循环进行遍历，时间复杂度O(N^2)。
int[] twoSum(int[] nums, int target) {
    for (int i=0;i<nums.length;i++)
        for (int j=i;j<nums.length;j++)
            if (nums[i]+nums[j]==target)
                return new int[] {i,j};

    //不存在
    return new int[] {-1,-1};
}

//使用哈希表减少时间复杂度：
int[] twoSum(int[] nums,int target) {
    int n =nums.length;
    index<Integer,Integer> index= new HashMap<>();
    //构造哈希表，元素映射到相应的索引
    for (int i=0;i<n;i++)
        index.put(nums[i],i);

    for (int i=0;i<n;i++){
        int other=target-nums[i];
        //如果other存在且不是nums[i]本身
        if (index.containsKey(other) && index.get(other) !=i)
            return new int[]{i,index.get(other)};
    }

    return new int[] {-1,-1};
}

//上述是很简单的twosum问题，主要的方法就是合理使用哈希表来处理问题。继续
//TwoSum II
//设计一个类，拥有两个API：
class TwoSum {
    // 向数据结构中添加一个数number
    public void add(int number);
    //寻找当前数据结构中是否存在两个数的和为value
    public boolean find(int value);
}
//如何实现这两个API呢，使用一个哈希表辅助find。
class TwoSum{
    Map<Integer,Integer> freq=new HashMap<>();

    public void add(int number) {
        //记录 number出现的次数
        freq.put(number, freq.getOrDefault(number,0)+1);
    }

    public boolean find(int value) {
        for (Integer key: freq.keySet()) {
            int other=value-key;
            //情况一
            if (other== key && freq.get(key)>1)
                return true;
            //情况二
            if (other != key && freq.containsKey(other))
                return true;
        }
        return false;
    }
}

        
