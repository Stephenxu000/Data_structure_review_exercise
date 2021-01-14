//5. 选择排序（Selection Sort）
/*
最简单直观的排序算法，为知识完整性而复习。
原理：
    在未排序序列中找到最大/小元素，存放到该排序序列起始位置。
    然后，再从剩余未排序元素中继续寻找最大/小元素，放到已排序序列末尾。
    以此类推，直到所有元素均排序完毕
5.1算法描述
    1.找min/max下标,两层循环
    2.外层循环i从0开始，表示已排序元素
    3.内层循环在[i+1,n]区间找最值，swap(nums[min],nums[i])
5.2
    最好 ||平均 || 最坏 时间复杂度O(n²) //以2为底 
    不稳定排序算法
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

void SelectionSort(vector<int> &nums)
{
    int minindex;//找最小元素下标
    for (int i = 0; i < nums.size(); i++)//已排序元素从0开始
    {
        minindex=i;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]<nums[minindex]){
                minindex=j;
            }
        }//在[j,n]中寻找最小元素，找到则选中与nums[i]交换
        swap(nums[minindex],nums[i]);
    }
}

int main()
{
    vector<int> a;
    init_vector(a);
    cout << "nums to be sorted :" << endl;
    print_vector(a);
    cout << "select sort :" << endl;
    SelectionSort(a);
    print_vector(a);
}