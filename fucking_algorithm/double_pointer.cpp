//双指针技巧
//双指针可以分为两类：快慢指针、左右指针。前者主要解决链表中的问题（链表有环）；后者解决数组or字符串中的问题，比如二分查找。
//
//一、快慢指针的常见算法
//一般初始化均指向头节点head,前进时fast在前，slow在后。
//
//1、判断链表是否有环
//单链表的特点是只知道下一个节点，因此需要两个指针来判断是否有环。
//不包含环的判断很简单，遍历完出现null即可。
class ListNode{
    int val;
    ListNode next;
}

bool hasCycle(ListNode head) {
    while (head!=null) //有环时会陷入死循环
        head=head.next;
    return false;
}

//经典方法为使用两个指针，一个快跑，一个慢跑，如果有环，最终快跑的会追上慢跑的。
bool hasCycle(ListNode head) {
    ListNode fast,slow;
    fast = slow =head;
    while (fast !=null && fast.next!=null){
        fast=fast.next.next;
        slow=slow.next;

        if (fast ==slow) return true;
    }
    return false;
}

//2、已知链表有环，返回环的起始位置
// 假设相遇时slow走了k步，则fast走了2k步，假设相遇点距离环起点为m步，那么环起点距离头节点为k-m步，(slow不可能走超过一圈，因为会被2倍速追上)。
// 此外，由于fast走了2k步，那么相遇时fast在圈里走了2k-k=k步，由于相遇点距离起点为m步，k-m步即为fast再次走到起点的距离.
// 这样，只需要在相遇时让一个指针指向头节点，然后他们再次相遇时的节点即为入口
ListNode detectCycle(ListNode head) {
        ListNode fast, slow;
        fast = slow = head;
        while (fast != null && fast.next != null) {
        fast = fast.next.next;
        slow = slow.next;
        if (fast == slow) break;
        }
        // 上面的代码类似 hasCycle 函数
        slow = head;
        while (slow != fast) {
            fast = fast.next;
            slow = slow.next;
        }
        return slow;
}

//3、寻找链表的中点
//类似地，快指针走两步，慢指针走一步，最后fast遍历完，slow所在就在中点
while ( fast!=null && fast.next!=null) {
    fast=fast.next.next;
    slow=slow.next;
}
return slow;
//当链表长度为奇偶时会有少许差别。
//中点的一个重要作用是做归并排序。
//归并排序：求中点索引递归地把数组二分，最后合并两个有序数组。

//4、寻找链表的倒数第k个元素
//类似地，这里让fast先走k步，然后两者齐步走
ListNode slow,fast;
slow=fast=head;
while(k-->0)
    fast=fast.next;
while (fast!=null ) {
    fast=fast.next;
    slow=slow.next;
}
return slow;


//二、左右指针的常用算法
// 左右指针在数组中通常表示为两个索引，比如left=0,right=nums.length-1;
// 1、二分查找
int binarySearch(int[] nums, int target) {
        int left = 0; 
        int right = nums.length - 1;
        while(left <= right) {
            int mid = (right + left) / 2;
            if(nums[mid] == target)
                return mid; 
            else if (nums[mid] < target)
                left = mid + 1; 
            else if (nums[mid] > target)
                right = mid - 1;
        }
        return -1;
}

//2、两数之和
//Two sum（leetcode)：给定一个升序数组，找到两个数使其和等于目标数。
//返回index1 & index2， index1<index2.
//返回的索引从1开始（不是从0）
//In: [2,7,11,15] target=9
//out:[1,2]
//解法：类似于二分查找
int[] twoSum(int[] nums,int target) {
    int left=0,right=nums.length-1;
    while (left<right){
        int sum=nums[left]+nums[right];
        if ( sum==target)
            return new int[]{left+1,right+1};
        else if (sum<target)
            left++;
        else if (sum>target)
            right--;
    }
    return -1;
}

//3、反转数组
void reverse(int[] nums){
    int left=0;
    int right=nums.length-1;
    while (left<right){
        int tmp=nums[left];
        nums[left]=nums[right];
        nums[right]=tmp;
        left++;right--;
    }
    return nums;
}
