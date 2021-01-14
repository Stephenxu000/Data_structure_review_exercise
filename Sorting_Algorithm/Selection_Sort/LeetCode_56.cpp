/*
https://leetcode-cn.com/problems/merge-intervals/

56. Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi]
merge all overlapping intervals
return an array of the non-overlapping intervals that cover all the intervals in the input.
来源：力扣（LeetCode）
*/
//runtime：464ms | 内存消耗 13.9MB
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    //先将二维数组按照左区间递增排序
    void SelectSort(vector<vector<int>> &nums)
    {
        int minindex;
        for (int i = 0; i < nums.size(); i++)
        {
            minindex = i;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j][0] < nums[minindex][0])
                {
                    minindex = j;
                }
            }
            swap(nums[minindex], nums[i]);
        }
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)//若区间数组只有一个或没有区间，直接返回区间数组。
            return intervals;
        SelectSort(intervals);
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size() - 1; i++)
        {
            if (intervals[i + 1][0] <= intervals[i][1])
            { //[a,b][c,d]满足条件c<b，开始合并
                if (intervals[i][1] >= intervals[i + 1][1])
                { //情况1.b>=d 合并为[a,b]
                    intervals[i + 1] = intervals[i];
                }
                else
                { //情况2.b>d 合并为[a,d]
                    intervals[i + 1] = {intervals[i][0], intervals[i + 1][1]};
                }
            }
            else
            { //不能合并，将区间保存进答案数组
                ans.push_back(intervals[i]);
            }
            if (i == intervals.size() - 2)
            { //最后一个区间记得加入，因为每次更新的都是intervals[i+1]
                ans.push_back(intervals[i + 1]);
            }
        }
        return ans;
    }
};