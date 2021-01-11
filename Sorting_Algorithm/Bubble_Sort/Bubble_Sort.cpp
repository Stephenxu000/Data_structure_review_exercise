//1. 冒泡排序（Bubble Sort）
/*
1.1算法描述
    1.相邻元素 a,b; if a>b; swap(a,b)；
    2.for(开始；结尾；每一对)//一层循环
    3.除最后一个，对所有一对元素重复以上步骤//二层循环
    4.重复步骤1~3，直到排序完成。
1.2
    时间复杂度O(n²)
    稳定排序算法
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

//基础版
/*理解：实际上每次外层循环会把最大的移到最后.（即最大数像冒泡一样上浮）
二层循环去除排好的一位,再重复i-1遍。即把从0到i区间中的每一对都比较，再次把0到i范围内的最大移到最后。
重复size()-1次就排完了。
*/
void BSort(vector<int> &nums)
{
    for (int i = nums.size() - 1; i >= 1; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}
//改进冒泡
/*
从基础版发现每一趟比较，到某个位置i开始，不再进行记录交换。
即说明a[i+1]~a[n]已经排序完毕，则范围直接缩到区间[开始，i]。
如果某一次内循环一次交换都没有，说明前面元素已经有序，此时算法结束。
*/
void Bubble(vector<int> &nums)
{
    //1.终止位置、是否交换初始化
    int pos = 0;             //标记循环里最后一次交换位置。
    int k = nums.size() - 1; //表示内循环的区间[0,k]
     //2.冒泡过程
    for (int i = nums.size() - 1; i >= 1; i--)
    {
        int flag = 0; //标记内循环是否发生交换
        for (int j = 0; j < k; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                flag = 1; //只要发生改变，则赋值1
                pos = j;  //循环最后一次交换位置赋值j
            }
        }
        k = pos; //更新内层循环遍历区间[开始,最后一次交换位置i]
        if (flag == 0)
        {
            return;
        }
    }
}
int main()
{
    //1.基础版测试
    cout << "1.base test" << endl;
    vector<int> a;
    init_vector(a);
    print_vector(a);
    BSort(a);
    print_vector(a);
    cout << "2.improve test" << endl;
    //2.改进版测试
    vector<int> b;
    init_vector(b);
    Bubble(b);
    print_vector(b);
}
