/*
https://leetcode-cn.com/problems/sort-an-array/

Given an array of integers nums, sort the array in ascending order.

Constrains:
1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000

来源：力扣（LeetCode）
*/
/*
此题若还是使用冒泡排序，是会超时的。因为冒泡排序的平均复杂度为O(n²)
现在，让我们用刚刚复习完的快速排序来解决这个问题
使用快排 runtime 68ms | 内存消耗 15.8MB 
*/
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    //1.划分函数
    int partition(vector<int> &nums, int start, int end)
    {
        int s = start;
        int pivot = nums[start];
        while (start < end)
        {
            while (nums[start] <= pivot && start < end) //开始找大元素
            {
                start++;
            }
            while (nums[end] > pivot) //结尾找小或等元素
            {
                end--;
            }
            if (start < end)
            {
                swap(nums[start], nums[end]);
            }
        }
        swap(nums[end], nums[s]);
        return end;
    }
    //2.非递归的快速排序
    void Qsort(vector<int> &nums)
    {
        //1.堆栈初始化
        stack<int> s;
        //2.参数初始化
        int start = 0, end = nums.size() - 1;
        s.push(end);
        s.push(start);
        //3.快排
        while (!s.empty())
        {
            start = s.top();
            s.pop();
            end = s.top();
            s.pop();
            if (start < end)
            { //默写时注意这个判断条件
                int pos = partition(nums, start, end);
                if (start < pos)
                {
                    s.push(pos - 1);
                    s.push(start);
                }
                if (end > pos)
                {
                    s.push(end);
                    s.push(pos + 1);
                }
            }
        }
    }
    vector<int> sortArray(vector<int> &nums)
    {
        Qsort(nums);
        return nums;
    }
};