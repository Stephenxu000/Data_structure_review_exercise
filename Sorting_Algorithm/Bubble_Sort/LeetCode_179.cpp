/*
https://leetcode-cn.com/problems/largest-number/

Given a list of non-negative(非负) integers nums, arrange them such that they form the largest number.
Note: The result may be very large, so you need to return a string instead of an integer.
来源：力扣（LeetCode）

*/
/*
此题可以用冒泡排序，base runtime 116ms||improve runtime 100ms，内存消耗11MB。
速度并不理想，可以用来复习冒泡排序。
*/
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        string ans;
        //俩俩组合比较生成的数字 若后大于前则交换
        for (int i = nums.size() - 1; i >= 1; i--)
        {
            for (int j = 0; j <= i - 1; j++)
            {
                string s1 = to_string(nums[j]) + to_string(nums[j + 1]);
                string s2 = to_string(nums[j + 1]) + to_string(nums[j]);
                if (s1 < s2)
                {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            ans += to_string(nums[i]);
        }
        if (nums[0] == 0)
        { //若最大的第一位为0，直接返回0。
            return "0";
        }
        else
        {
            return ans;
        }
    }
};