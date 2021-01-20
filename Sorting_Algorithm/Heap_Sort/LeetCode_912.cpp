/*
https://leetcode-cn.com/problems/sort-an-array/

Given an array of integers nums, sort the array in ascending order.

Constrains:
1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000

来源：力扣（LeetCode）
*/
/*
使用冒泡 超时
使用快排 runtime 68ms | 内存消耗 15.8MB 
使用插入 超时
使用希尔 runtime 44ms | 内存消耗 15MB
使用选择 超时
使用堆排序 runtime 36ms | 内存消耗 15.3MB
*/
#include <vector>
using namespace std;
class Solution
{
public:
    //重建堆
    void rebulidheap(vector<int> &nums, int root, int n)
    {
        int index = root, left, maxindex = root;
        while (index <= n / 2 - 1)
        {
            left = index * 2 + 1; //left在while循环里赋值
            if (left < n - 1 && nums[left] < nums[left + 1])
            {
                maxindex = left + 1;
            } //此处还顺便确认是否存在右节点，顺序不能乱。
            else
            {
                maxindex = left;
            }
            if (nums[index] < nums[maxindex])
            {
                swap(nums[index], nums[maxindex]);
                index = maxindex; //继续重建堆
            }
            else
            {
                index = n; //循环出口
            }
        }
    }
    //堆排序
    void HeapSort(vector<int> &nums)
    {
        int i;
        //初始建大顶堆
        for (i = nums.size() / 2 - 1; i >= 0; i--)
        { //第一个循环从非子节点的第一个节点往前一次一次建堆
            rebulidheap(nums, i, nums.size());
        }
        //交换再建堆
        for (i = nums.size() - 1; i > 0; i--)
        {
            swap(nums[0], nums[i]);
            rebulidheap(nums, 0, i);
        }
    }
    vector<int> sortArray(vector<int> &nums)
    {
        HeapSort(nums);
        return nums;
    }
};