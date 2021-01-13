/*
https://leetcode-cn.com/problems/relative-ranks/

Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: 
    The first three athletes got the top three highest scores.
    so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
    For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
1.N is a positive integer and won't exceed 10,000.
2.All the scores of athletes are guaranteed to be unique.

来源：力扣（LeetCode）
*/
//runtime 20ms | 内存消耗 12.2MB 

#include <vector>
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
public:
    void ShellSort(vector<int> &nums)
    {
        int pre, current;
        for (int gap = floor(nums.size() / 2); gap > 0; gap = floor(gap / 2))
        {
            for (int i = gap; i < nums.size(); i++)
            {
                pre = i - gap;
                current = nums[i];
                while (pre >= 0 && current > nums[pre])
                {                                //倒序
                    nums[pre + gap] = nums[pre]; //后移动
                    pre = pre - gap;
                }
                nums[pre + gap] = current;
            }
        }
    }
    vector<string> findRelativeRanks(vector<int> &nums)
    {

        int i;
        vector<int> order = nums;           //保存原数组顺序 重载等号？需要研究一下源码
        ShellSort(nums);                    //降序排序
        unordered_map<int, string> hashmap; //得分 排名创建键值对
        for (i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                hashmap[nums[i]] = "Gold Medal";
            }
            else if (i == 1)
            {
                hashmap[nums[i]] = "Silver Medal";
            }
            else if (i == 2)
            {
                hashmap[nums[i]] = "Bronze Medal";
            }
            else
            {
                hashmap[nums[i]] = to_string(i + 1);
            }
        }
        vector<string> ans;
        for (i = 0; i < nums.size(); i++)
        {
            ans.push_back(hashmap[order[i]]);
        }
        return ans;
    }
};