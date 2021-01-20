/*
https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
来源：力扣（LeetCode）
*/
/*
使用堆排序 runtime 4ms | 内存消耗 9.7MB
*/
class Solution
{
public:
    //建完最大堆后最大就知道了，再循环k-1次，就是第k大的元素
    void rebuildheap(vector<int> &nums, int root, int n)
    {
        int index = root, mindex = root, left;
        while (index <= n / 2 - 1)
        { //<=
            left = index * 2 + 1;
            if (left < n - 1 && nums[left] < nums[left + 1])
            {
                mindex = left + 1;
            }
            else
            {
                mindex = left;
            }
            if (nums[index] < nums[mindex])
            {
                swap(nums[index], nums[mindex]);
                index = mindex;
            }
            else
            {
                index = n;
            }
        }
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        //先建立大顶堆
        int i;
        for (i = nums.size() / 2 - 1; i >= 0; i--)
        {
            rebuildheap(nums, i, nums.size()); //!!!root=i，不是0
        }
        i = nums.size() - 1;
        while (k != 0)
        {
            if (k == 1)
            {
                return nums[0];
            }
            k--;
            swap(nums[0], nums[i]);
            rebuildheap(nums, 0, i--);
        }
        return -1;
    }
};