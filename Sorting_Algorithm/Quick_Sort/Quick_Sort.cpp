//2. 快速排序（Quick Sort）
/*
本质：冒泡排序基础上的递归分治法。
2.1算法描述
    1.数列挑出一元素（“基准”pivot）
    2.分区操作（partition）：所有比基准小的放在基准前面；比基准大的放后面
    3.递归地（recursive）把小于基准元素和大于基准元素的子数列排序
2.2
    最好||平均 时间复杂度O(nlogn) //以2为底 
    不稳定排序算法
*/

#include <vector>
#include <iostream>
#include <stack>
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
对一组区间为[m,n]数据进行分组操作
算法返回基准元素在分区操作后的位置下标
*/
int Partition_1(vector<int> &nums, int start, int end)
{
    int i = start, j = end;
    int pivot = nums[start]; //默认第一个元素为基准元素
    while (i < j)
    {
        while (nums[i] <= pivot&&i<j)//防止i<end越界
        {
            i++;
        } //从基准往右开始找第一个比基准大的元素
        while (nums[j] > pivot)
        {
            j--;
        } //从最右开始往左找第一个比基准小或等于（防止j<start）的元素
        if (i < j)
        {
            swap(nums[i], nums[j]); //i大元素，j小元素交换
        }
    }
    swap(nums[start], nums[j]); //基准元素（默认为分组第一个）与在最右的最小元素交换
    return j;
}
//1.快排的递归版本 在区间[m,n]上进行递归
void QSort(vector<int> &nums, int m, int n)
{
    //1.递归出口
    if (m >= n)
        return;
    //2.快排操作
    if (m < n)
    {
        int j = Partition_1(nums, m, n); //对[m,n]区间进行分组操作
        QSort(nums, m, j - 1);           //对[m,基准元素-1]快排
        QSort(nums, j + 1, n);           //对[基准元素+1,n]快排
    }
}
/*
对于快速排序，待排序的文件已基本有序是不利的：（若完全有序，最坏情况分析如下）
    第一趟划分，基准定在原地，左子序列空，右子序列n-1
    第二趟划分，第二记录（第二趟基准）原地，左空，右n-2
    即做n-1次分组操作,第i次分组处理n-i+1个元素 [i-1,n]
    此时最坏复杂度为 O(n²)

    由一系列证明可知，对于随机产生的数据，快排时间复杂度为O(nlogn)
    思路1：用随机函数选择控制分划记录 即把第一个与后面随机抽一个交换，以随机出来的第一个为基准。（随机数产生费时，不理想）
    思路2：三者取中法，即nums[start]是nums[start] nums[end] nums[(start+end)/2]的中间值
*/
//划分思路2：三者取中法实现
int Partition_2(vector<int> &nums, int start, int end)
{
    //1.取三者中间值=nums[start]为基准
    swap(nums[(start + end) / 2], nums[start + 1]);
    if (nums[start + 1] > nums[end])
        swap(nums[start + 1], nums[end]);
    if (nums[start] > nums[end])
        swap(nums[start], nums[end]); //前两步将最大的移到了end
    if (nums[start + 1] > nums[start])
        swap(nums[start + 1], nums[start]); //把第二大(中间值)移到start

    //2.分划初始化
    int i = start, j = end, pivot = nums[start];

    //3.标准分划操作
    while (i < j)
    {
        while (nums[i] <= pivot&&i<j)
        {
            i++;
        }
        while (nums[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[start], nums[j]);
    return j;
}
//2.快排的非递归版本
void Hsort(vector<int> &nums)
{
    //1.堆栈初始化
    stack<int> s;
    //2.局部参数初始化
    int start = 0, end = nums.size() - 1;
    //将初始状态的区间压栈[start,end]
    s.push(end);   //右区间
    s.push(start); //左区间
    while (!s.empty())
    {
        start = s.top();
        s.pop(); //先弹出左
        end = s.top();
        s.pop(); //再弹出右
        if (start < end)
        {
            //划分操作
            int pos = Partition_2(nums, start, end);
            if (pos > start)
            {
                s.push(pos - 1);
                s.push(start);
                //区间[start,pos-1]
            }
            if (end > pos)
            {
                s.push(end);
                s.push(pos + 1);
                //区间[pos+1,end]
            }
        }
    }
}
int main()
{
    vector<int> a, b;
    init_vector(a);
    init_vector(b);
    cout << "nums to be sorted :" << endl;
    print_vector(a);
    cout << "recursive version :" << endl;
    QSort(a, 0, a.size() - 1);
    print_vector(a);
    cout << "Non-recursive version:" << endl;
    Hsort(b);
    print_vector(b);
}