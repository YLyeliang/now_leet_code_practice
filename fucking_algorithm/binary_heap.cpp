//二叉堆，相比BST更简单。主要操作就两个，sink（下沉）和swim（上浮），用以维护二叉堆的性质。
//主要应用有两个：堆排序；优先级队列。

// 一、二叉堆概览
// 二叉堆本质上就是一种特殊的二叉树（完全二叉树），只不过存储再数组里。一般的链表二叉树，
// 操作结点的指针，而再数组里，将数组索引作为指针：

// 父节点的索引
int parent(int root) {
    return root/2;
}
// 左孩子索引
int left(int root) {
    return root * 2;
}
// 右孩子索引
int right( int root) {
    return root *2 +1;
}
//例子
//i:      0 1 2 3 4 5 6 7
//arr[i]: * T S R P N O A
//       T
//     S   R
//    P N O A

// 二叉堆还分为最大堆和最小堆。
// 最大堆：每个节点都大于等于它的两个子节点
// 最小堆：每个节点都小于等于它的子节点
// 以最大堆为例，arr[1]一定为最大值

// 二、优先级队列概览
// 优势：插入或者删除元素时，元素会自动排序，这里面底层就是二叉堆的操作
// 数据结构的功能无非就是增改删查，优先级队列有两个主要API:insert和delMax（如果底层用最小堆，则delMin)
// 先实现一个简化的优先级队列
// 以java为例，key可以是任何一种可比较大小的数据类型，可以假设是int char等。
public class MaxPQ
    <key extends Comparable<key>> {
    //存储元素的数组
    private key[] pq;
    // 当前 Priority queue中的元素
    private int N =0;
    public MaxPQ(int cap) {
        // 索引0不用，所以多分配一个空间
        pq = (key[]) new Comparable[cap+1];
    }

    // 返回当前队列的最大元素
    public key max() {
        return pq[1];
    }

    // 插入元素
    public void insert(key e) {..}

    // 删除并返回当前队列的最大元素
    public key delMax() {...}

    // 上浮第k个元素，以维护最大堆性质
    private void swim(int k) {...}

    // 下沉第k个元素，以维护最大堆性质
    private void sink(int k) {...}

    // 交换数组的两个元素
    private void exch(int i, int j) {
        key tmp=pq[i];
        pq[i]=pq[j];
        pq[j]=tmp;
    }

    // pq[i]是否比pq[j]小
    private boolean less (int i, int j) {
        return pq[i].CompareTo(pq[j]) <0;
    }

    // left, right, parent 
}


// 三、实现swim和sink
// 以最大堆为例，在删除和插入时，难免会破坏最大堆的结构，需要通过这两个操作进行维护。
// 破坏的情况有两种：
// 1、某个节点A比它的子节点小，这时候应该将其与子节点替换，让更大的上来做父节点，需要对A下沉。
// 2、某个节点A比它的父节点大，这时候应该让其做父节点，需要对A上浮。
// 并且，这个操作很可能需要多次才能完成，需要有while循环
// 上浮：
private void swim(int k) {
    //若浮到堆顶，就不能继续
    while (k>1 && less(parent(k),k)){
        //若第k个元素比上层大
        //将k换上去
        exch(parent(k),k);
        k = parent(k);
    }
}

//下沉
private void sink(int k) {
    // 若沉到堆底，就不能继续
    while (left(k)<=N) {
        // 先假设左边节点较大
        int older = left(k);
        // 若右边节点存在，比较大小
        if ( right(k)<=N && less(older,right(k)))
            older=right(k);
        // 若k比两个子节点都大，则不必下沉
        if (less(older,k)) break;
        //否则，下沉
        exch(k,older);
        k = older;
    }
}

// 四、实现delMax和insert
// insert方法先将元素插入到堆底最后，然后上浮到正确位置
public void insert(key e) {
    N++;
    pq[N] = e;
    swim(N);
}

//delMax 先将堆顶元素A和堆底元素B进行对调，然后删除A，并将B下沉
public key delMax() {
    // 最大堆堆顶即为最大元素
    key max=pq[1];
    //将该元素换到最后，删除
    exch(1,N]);
    pq[N]=NULL;
    N--;
    sink(1);
    return max;
}

// 优先级队列就完成了，插入和删除的时间复杂度为O（logk),k为元素总数。不管上浮还是下沉，最多也就操作堆的高度个次数
// 。

