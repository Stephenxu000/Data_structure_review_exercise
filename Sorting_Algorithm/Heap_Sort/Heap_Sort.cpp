//6. 堆排序（Heap Sort）
/*
利用堆设计的排序算法。
堆是一个近似完全二叉树的结构，且满足子节点键值总是小于/大于它的父节点
6.1算法描述
    1.构造初始堆(一般升序大顶堆，降序小顶堆)
    2.将堆顶元素与末尾元素进行交换，使末尾元素最大。size--
    3.重复步骤1，2。反复执行建堆+交换步骤，直到整个序列有序。
6.2
    最好 ||平均 || 最坏 时间复杂度O(nlogn) //以2为底 
    不稳定排序算法
6.3
    大根堆：根结点对应元素最大（小根堆即最小）

*/
#include <vector>
#include <iostream>
using namespace std;
//打印函数
void print_vector(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << "a[" << i << "]=" << a[i] << " ";
    }
    cout << endl;
}
//数组初始化
void init_vector(vector<int> &a)
{
    a.push_back(7);
    a.push_back(9);
    a.push_back(2);
    a.push_back(16);
    a.push_back(8);
    a.push_back(5);
    a.push_back(12);
    a.push_back(13);
    a.push_back(14);
} //7 9 2 16 8 5 12 13 14

void rebuildheap(vector<int> &nums, int root, int n) //重建堆
{
    //1.初始化：i指向树根
    int i = root, lchild, maxindex = root;
    while (i <= n / 2 - 1)
    {
        lchild = 2 * i + 1; //左子节点 左+1为右子节点   eg.root：0 左1 右2
        if (lchild < n - 1 && nums[lchild] < nums[lchild + 1])
        {
            maxindex = lchild + 1; //右子结点大，记录大的下标
        }
        else
        {
            maxindex = lchild;
        }
        //nums[maxindex]是nums[i]具有较大关键词的子结点
        if (nums[maxindex] > nums[i])
        {
            swap(nums[maxindex], nums[i]);
            i = maxindex; //继续重建堆
        }
        else
        {
            i = n; //终止循环
        }
    }
}
void HeapSort(vector<int> &nums)
{
    //1.初始建堆
    int i;
    for (i = nums.size() / 2 - 1; i >= 0; i--)
    {
        rebuildheap(nums, i, nums.size());
    }
    //2.排序
    for (i = nums.size() - 1; i > 0; i--)
    {
        swap(nums[0], nums[i]);//交换堆顶和末尾元素
        rebuildheap(nums, 0, i);//重建堆
    }
}
int main()
{
    vector<int> a;
    init_vector(a);
    cout << "nums to be sorted :" << endl;
    print_vector(a);
    cout << "Heap Sort :" << endl;
    HeapSort(a);
    print_vector(a);
}