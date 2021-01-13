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
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    void ShellSort(vector<int> &nums)
    {
        int pre, current; //pre下标，current-gap向前遍历元素 current指向当前元素
        for (int gap = floor(nums.size() / 2); gap > 0; gap = floor(gap / 2))
        {
            for (int i = gap; i < nums.size(); i++)
            {
                pre = i - gap;
                current = nums[i];
                //已排序元素i-gap，从前向后扫描
                while (pre >= 0 && nums[pre] > current)
                {
                    nums[pre + gap] = nums[pre]; //往后移gap位
                    pre = pre - gap;
                }                          //找到最左的一个比当前元素大的位置记录下（即pre+gap），并将该元素后移gap位
                nums[pre + gap] = current; //在该位置下插入当前元素
            }
        }
    }
    vector<int> sortArray(vector<int> &nums)
    {
        ShellSort(nums);
        return nums;
    }
};