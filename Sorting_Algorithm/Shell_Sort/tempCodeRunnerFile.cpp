//4. 希尔排序（Shell Sort）
/*
本质：分组（缩小增量）的插入排序（简单插入排序 增量序列t=1）。
原因: 插入排序对于待排序记录数量较少、记录较有序时，时间复杂度低。
4.1算法描述
    1.选择一个增量序列t1,t2...tk,tk=1;(递减)
    2.把待排序记录按下标的一定增量分组（分组eg.2,2+t,2+2t ...2+nt<nums.size())
    3.对每组使用插入排序，随着增量减少，每组包含记录越来越多。
    4.当tk=1时，整个文件恰好分成一个组，算法终止。
4.2
    时间复杂度 最好 O(n) | 平均 O(n^1.3) | 最坏 O(n²) 
    不稳定排序算法
*/
#include <vector>
#include <iostream>
#include <math.h>
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

/*
此处提前取增量n/2,n/4,n/8,....1；
也可以动态定义增量序列。
*/
void ShellSort(vector<int> &nums)
{
    int pre, current; //pre下标，current-gap向前遍历元素 current指向当前元素
    for (int gap = floor(nums.size() / 2); gap > 0; gap = floor(gap / 2))
    {
        for (int i = gap; i < nums.size(); i++)
        {
            //在元素下标为（i,i-gap,i-2gap...）分组上进行插入排序
            pre = i - gap;
            current = nums[i];
            while (pre >= 0 && nums[pre] > current)
            {
                nums[pre + gap] = nums[pre];//向后移动gap位
                pre = pre - gap; //简单插入排序为pre--；向前移动gap位
            }//找到该组最左的一个比当前元素大的位置记录下（即pre+gap），并将该元素后移一位
            nums[pre+gap] = current;//在该位置下插入当前元素
        }
    }
}

int main()
{
    vector<int> a;
    init_vector(a);
    cout << "nums to be sorted :" << endl;
    print_vector(a);
    cout << "Shell Sort :" << endl;
    ShellSort(a);
    print_vector(a);
}